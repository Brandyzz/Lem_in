/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:53:41 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/20 16:53:43 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bitprint(unsigned int nb)
{
	int	i;
	int	sp;

	sp = 1;
	i = 8 * sizeof(nb) - 1;
	while (i >= 0)
	{
		(nb & (1 << i)) ? ft_putchar('1') : ft_putchar('0');
		i--;
		if (sp % 4 == 0)
			ft_putchar(' ');
		sp++;
	}
	ft_putchar('\n');
}
