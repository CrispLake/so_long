/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:08:09 by emajuri           #+#    #+#             */
/*   Updated: 2022/11/07 21:08:47 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	size_t	lstlen;
	t_list	*head;
	t_list	*tmp;

	lstlen = ft_lstsize(lst);
	head = ft_lstnew(f(lst->content));
	if (lst->next)
		lst = lst->next;
	if (!head)
		return (0);
	while (--lstlen)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, tmp);
		lst = lst->next;
	}
	return (head);
}
