/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:10:37 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/23 16:46:28 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*element;
	t_list	*new_list;
	void	*content;

	if (lst == NULL || (*f) == NULL || (*del) == NULL)
		return (NULL);
	new_list = NULL;
	while (lst != NULL)
	{
		content = (*f)(lst->content);
		element = ft_lstnew(content);
		if (element == NULL)
		{
			del(content);
			ft_lstclear(&new_list, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_list, element);
		lst = lst->next;
	}
	return (new_list);
}
