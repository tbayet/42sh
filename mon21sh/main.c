/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 11:08:18 by jbobin            #+#    #+#             */
/*   Updated: 2016/09/21 13:01:07 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		**ft_get_path(char **environ)
{
	char	**path;
	char	*tmp;
	int		i;

	i = 0;
	path = NULL;
	while (environ != NULL && environ[i] != NULL)
	{
		if (ft_strncmp("PATH=", environ[i], 5) == 0)
			path = ft_strsplit(&environ[i][5], ':');
		i++;
	}
	i = 0;
	while (environ != NULL && path != NULL && path[i] != NULL)
	{
		if (path[i][0] != '\0' && path[i][ft_strlen(path[i]) - 1] != '/')
		{
			tmp = ft_strjoin(path[i], "/");
			ft_strdel(&path[i]);
			path[i] = tmp;
		}
		i++;
	}
	return (path);
}

static void	ft_pipe(t_prstruct *proc, char **buf, char **env[3], char **path)
{
	while (proc->i <= proc->npipe)
	{
		proc->s = 0;
		while (buf[proc->i][proc->s] == '\t' || buf[proc->i][proc->s] == ' ')
			proc->s++;
		if (ft_exe_builtin(proc->s, buf[proc->i], env, path))
			return ;
		proc->father = ft_fork(&proc->list);
		if (proc->father == 0)
			ft_son(proc, buf, env, path);
		else if (proc->i > 0)
			ft_close_pipe(proc->pipe, proc);
		proc->i++;
	}
	while (proc->father != proc->id)
	{
		proc->id = wait(NULL);
		ft_kill_process(&proc->list, proc->id);
	}
}

static void	ft_process(char *buf, char **env[3], char **path, t_hered *heredoc)
{
	t_prstruct	process;
	char		**tmp;

	signal(2, &ft_sig_stop_ex);
	process.list = NULL;
	process.i = 0;
	process.heredoc = heredoc;
	if ((process.npipe = ft_count_pipe(buf)) == -1)
	{
		ft_putendl_fd("21sh: parse error", 2);
		signal(2, &ft_signal_stop);
		return ;
	}
	process.pipe = ft_create_pipe(process.npipe);
	tmp = ft_strsplit(buf, '|');
	ft_pipe(&process, tmp, env, path);
	ft_free_tab(&tmp);
	ft_free_list(&process.list);
	signal(2, &ft_signal_stop);
}

static void	ft_loop(char **env[3], t_termcaps *cap)
{
	char	**path;
	char	**com;
	char	*tmp;
	int		j;

	while (42 && !(j = 0))
	{
		path = ft_get_path(env[0]);
		env[1] = ft_tabdup(env[2]);
		if (ft_read_termcap(cap) == 1)
			exit(0);
		ft_reset_term(0);
		tmp = cap->cmd ? cap->cmd : cap->str;
		com = ft_strsplit(tmp, ';');
		while (com != NULL && com[j] != NULL)
		{
			ft_process(com[j], env, path, cap->heredoc);
			j++;
		}
		ft_main_free(&env[1], cap, &path, &com);
		if (env[0] != NULL && env[1] != NULL && env[2] != NULL)
			ft_sync_env(env, 0, 0, 0);
	}
}

int			main(void)
{
	char			**env[3];
	t_termcaps		*cap;

	signal(2, &ft_signal_stop);
	signal(18, SIG_IGN);
	signal(28, &ft_signal_size);
	env[0] = ft_create_environ(0);
	env[2] = ft_tabdup(env[0]);
	cap = ft_struct_innit(0);
	ft_init_termcap(cap);
	ft_loop(env, cap);
	return (0);
}