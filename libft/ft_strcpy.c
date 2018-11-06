/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 08:27:08 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/21 08:08:10 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dst, const char *src)
{
	char	*result;

	if (src == dst)
		return (dst);
	result = dst;
	while (*src != 0)
		*dst++ = *src++;
	*dst = 0;
	return (result);
}
