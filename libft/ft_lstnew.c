/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:26:38 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/22 16:04:25 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *result;

	result = (t_list*)malloc(sizeof(t_list));
	if (result == NULL)
		return (NULL);
	result->next = NULL;
	result->content_size = (content == NULL) ? 0 : content_size;
	result->content = content == NULL ? NULL : malloc(content_size);
	if (result->content == NULL && content != NULL)
	{
		free(result);
		return (NULL);
	}
	if (content != NULL)
		ft_memcpy(result->content, (void*)content, content_size);
	return (result);
}
