/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_histo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:23:22 by pbourdon          #+#    #+#             */
/*   Updated: 2016/10/01 16:24:17 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init_histo(t_prstruct *proc)
{
	t_dlist		*histo;

	histo = NULL;
	histo = dlist_new(histo);
	if (ft_get_home(proc->env[2]) != NULL)
		ft_get_history_from_file(histo, open(ft_strjoin(ft_get_home(
			proc->env[2]), "/.42sh"), O_RDONLY), 0, 0);
	else
	{
		ft_putstr("The history file is not available. Please set the home");
		ft_putstr(" env variable\n");
	}
	
	proc->histo2 = histo;
}
