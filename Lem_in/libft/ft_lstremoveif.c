/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremoveif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:55:11 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/20 16:55:14 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremoveif(t_list *head, void *data_ref)
{
	t_list	*tmp;
	t_list	*victim;

	tmp = head;
	if (tmp->next == NULL &&
			ft_memcmp(head->content, data_ref, head->content_size) == 0)
	{
		head = NULL;
		return ;
	}
	while (tmp)
	{
		if (ft_memcmp(head->content, data_ref, head->content_size) == 0)
		{
			victim->next = tmp->next;
			free(tmp);
			tmp = victim;
		}
		else
			victim = tmp;
		tmp = tmp->next;
	}
}
