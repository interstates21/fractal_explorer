/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 19:50:00 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/05 19:55:53 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list	*elem))
{
	t_list	*current;
	t_list	*next;

	if (lst == NULL || f == NULL)
		return ;
	current = lst;
	if (current != 0)
		next = current->next;
	while (current != 0)
	{
		f(current);
		current = next;
		if (next != 0)
			next = next->next;
	}
}
