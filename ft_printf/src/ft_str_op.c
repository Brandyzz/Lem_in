/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:45:29 by cpollich          #+#    #+#             */
/*   Updated: 2019/09/21 15:09:38 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			str_clean(t_string **s)
{
	if (s && *s)
	{
		ft_strdel(&(*s)->data);
		(*s)->capacity = 0;
		(*s)->size = 0;
	}
}

void			str_destroy(t_string **s)
{
	if (s && *s)
	{
		ft_strdel(&(*s)->data);
		(*s)->capacity = 0;
		(*s)->size = 0;
		free(*s);
		*s = NULL;
	}
}
