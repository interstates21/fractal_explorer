/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewasis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:14:36 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/16 19:19:04 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnewasis(void const *content, size_t content_size)
{
	t_list *result;

	result = malloc(sizeof(t_list));
	if (result == NULL)
		return (NULL);
	result->next = NULL;
	result->content_size = (content == NULL) ? 0 : content_size;
	result->content = (void*)content;
	return (result);
}
