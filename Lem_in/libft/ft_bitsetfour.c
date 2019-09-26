/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitsetfour.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:53:46 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/20 16:53:49 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bitsetfour(unsigned int *i, unsigned int val, unsigned int index)
{
	int	n;

	n = *i;
	n = (n & ~(15 << index * 4)) | (val << index * 4);
	*i = n;
}
