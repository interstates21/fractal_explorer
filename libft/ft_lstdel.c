/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:09:15 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/05 19:29:13 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;
	t_list	*next;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	current = *alst;
	next = current->next;
	while (next != 0)
	{
		del(current->content, current->content_size);
		free(current);
		current = next;
		next = next->next;
	}
	del(current->content, current->content_size);
	free(current);
	*alst = NULL;
}
