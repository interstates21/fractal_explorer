/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:02:38 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/01 16:02:39 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	unsigned char	*psrc;
	unsigned char	*pdst;

	psrc = src;
	pdst = dst;
	while (n-- > 0)
	{
		*pdst = *psrc;
		if (*psrc == (unsigned char)c)
			return (++pdst);
		psrc++;
		pdst++;
	}
	return (NULL);
}
