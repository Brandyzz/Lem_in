/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjory-ca <jjory-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 16:54:46 by jjory-ca          #+#    #+#             */
/*   Updated: 2019/08/20 16:54:49 by jjory-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*victim;

	while (*alst)
	{
		victim = *alst;
		*alst = (*alst)->next;
		del(victim->content, victim->content_size);
		free(victim);
	}
	*alst = NULL;
}
