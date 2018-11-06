/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 10:24:48 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/10/28 10:24:49 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *result;

	result = s1;
	while (*s1 != 0)
		s1++;
	while (*s2 != 0 && n)
	{
		*s1++ = *s2++;
		n--;
	}
	*s1 = 0;
	return (result);
}
