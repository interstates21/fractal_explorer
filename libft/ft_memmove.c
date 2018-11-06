/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:17:52 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/05 17:34:32 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, void *src, size_t n)
{
	void	*result;

	result = dst;
	if (src == dst)
		return (dst);
	while (n > 0)
	{
		n--;
		if (src < dst)
			*(char*)(dst + n) = *(char*)(src + n);
		else
			*(char*)dst++ = *(char*)src++;
	}
	return (result);
}
