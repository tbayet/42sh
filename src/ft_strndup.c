/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdenis <chdenis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:01:57 by tbayet            #+#    #+#             */
/*   Updated: 2016/12/02 18:57:17 by chdenis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
**	Meme chose que ft_strsub(s1, 0, n);
*/

char	*ft_strndup(const char *s1, size_t n)
{
	unsigned int	cpt;
	char			*s2;

	cpt = 0;
	s2 = (char*)malloc(sizeof(char) * (n + 1));
	while ((s1[cpt] != '\0') && (cpt < n))
	{
		s2[cpt] = s1[cpt];
		cpt++;
	}
	s2[cpt] = '\0';
	return (s2);
}
