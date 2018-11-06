/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 15:52:11 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/01 16:05:03 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	void	*result;

	result = dst;
	while (n > 0)
	{
		*(unsigned char*)dst++ = *(unsigned char*)src++;
		n--;
	}
	return (result);
}
