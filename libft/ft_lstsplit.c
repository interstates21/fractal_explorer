/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:44:29 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/16 19:22:41 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstsplit(char const *s, char c)
{
	t_list	*head;
	t_list	*lst;
	int		i;
	char	*word;

	lst = NULL;
	head = NULL;
	while (*s != 0)
	{
		if (*s != c)
		{
			i = 0;
			while (s[i] != c && s[i] != 0)
				i++;
			word = ft_strnew(sizeof(char) * (i + 1));
			while (*s != c && *s != 0)
				*word++ = *s++;
			lst != NULL ? lst->next = ft_lstnewasis(word - i, i) : 0;
			lst = (lst == NULL) ? ft_lstnewasis(word - i, i) : lst->next;
			head = (head == NULL) ? lst : head;
		}
		else
			s++;
	}
	return (head);
}
