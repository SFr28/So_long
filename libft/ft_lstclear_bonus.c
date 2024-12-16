/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:55:26 by sfraslin          #+#    #+#             */
/*   Updated: 2024/11/23 16:39:23 by sfraslin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if ((*del) == NULL)
		return ;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		ft_lstdelone((*lst), (*del));
		(*lst) = temp;
	}
	*lst = NULL;
}

/*void	ft_del(void *content)
{
	content = NULL;
}

int	main(void)
{
	t_list *l = ft_lstnew(strdup("nyancat"));
 
 	l->next = ft_lstnew(strdup("#TEST#"));
 	ft_lstclear(&l, &ft_del);
	return (0);
}*/
