/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:09:34 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/09/21 15:10:17 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *ap, t_token *token)
{
	int	w;
	int	p;

	w = token->width;
	p = token->precision;
	if (!ap)
	{
		return (((token->flags & F_MINUS) != F_MINUS) ?
			print_without_flag("(null)", w, p, ' ') :
			print_with_flag("(null)", w, p, ' '));
	}
	if ((token->flags & F_MINUS) != F_MINUS)
		return (print_without_flag(ap, w, p, ' '));
	else
		return (print_with_flag(ap, w, p, ' '));
}
