/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 10:24:48 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/01 18:10:44 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	result;
	int		src_len;

	result = 0;
	src_len = ft_strlen(src);
	while (*dst != 0)
	{
		dst++;
		result++;
	}
	if (result > size)
		return (size + src_len);
	size -= result;
	while (*src != 0 && size > 1)
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = 0;
	return (result + src_len);
}
