/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:58:51 by chdenis           #+#    #+#             */
/*   Updated: 2016/12/13 14:34:59 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_prstruct	*g_process;

/*
**	Parse $? pour le retour du dernier status code
*/

char			*parse_dollar_pipeline_exit_status(char *s)
{
	char	*c;
	int		cl;
	char	*status;

	if (!(status = ft_itoa(g_process->stat_lock)))
		return (s);
	c = s;
	while ((c = ft_strchr(c, '$')))
	{
		c++;
		cl = c - s;
		if (*c != '?')
			continue ;
		ft_strsplice(&s, c - 1, 2, status);
		c = s + cl;
	}
	free(status);
	return (s);
}

/*
**	Parse les variables pour l'affichage (exemple: echo $VARIABLE)
**	Si la variable n'existe pas, supprime simplement dans la string
*/

char			*parse_dollar_variable(char *s)
{
	char	*c;
	char	*e;
	char	*key;
	char	*value;
	int		cl;

	c = s;
	while ((c = ft_strchr(c, '$')))
	{
		key = NULL;
		e = ++c;
		cl = c - s;
		while (IS_ALPHA_DIGIT(*e))
			e++;
		if (e - c < 1)
			continue ;
		if (!(key = ft_strsub(c, 0, e - c)))
			return (s);
		if (!(value = env_getter(key)) && local_var_get(key))
			value = local_var_get(key)->value;
		ft_strsplice(&s, c - 1, e - c + 1, value);
		free(key);
		c = s + cl;
	}
	return (s);
}
