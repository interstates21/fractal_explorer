/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:50:43 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/10/30 14:01:10 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	void	*result;
	char	l;

	result = b;
	l = (unsigned char)c;
	while (len-- > 0)
	{
		*(char*)b = l;
		b++;
	}
	return (result);
}
