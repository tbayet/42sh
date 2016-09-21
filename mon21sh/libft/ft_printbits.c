/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbobin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:08:18 by jbobin            #+#    #+#             */
/*   Updated: 2015/12/07 14:26:15 by jbobin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_bits(unsigned char c)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (c >= i)
		{
			c = c - i;
			write(1, "1", 1);
		}
		else
		{
			write(1, "0", 1);
		}
		i = i / 2;
	}
}