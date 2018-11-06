/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 20:05:47 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/22 16:20:53 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		del_lst(t_list *lst)
{
	t_list	*next;

	while (lst != 0)
	{
		next = lst->next;
		free(lst->content);
		free(lst);
		lst = next;
	}
}

static t_list	*ft_lstcopy(t_list *lst, t_list *original)
{
	t_list *result;

	if (lst == NULL)
		return (NULL);
	if ((result = ft_lstnew(lst->content, lst->content_size)) == NULL)
	{
		if (lst != original)
			free(lst);
		return (NULL);
	}
	result->next = lst->next;
	if (lst != original)
		free(lst);
	return (result);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*head;

	if (lst == NULL || f == NULL)
		return (NULL);
	result = f(lst);
	head = result;
	if (head == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != 0)
	{
		result->next = ft_lstcopy(f(lst), lst);
		if (result->next == NULL)
			del_lst(head);
		result = result->next;
		lst = lst->next;
	}
	return (head);
}
