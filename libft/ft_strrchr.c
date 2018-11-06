/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 09:36:24 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/10/29 09:50:10 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *str, int c)
{
	const char	*result;
	char		find;

	find = (char)c;
	result = 0;
	while (*str != 0)
	{
		if (*str == find)
			result = str;
		str++;
	}
	if (find == 0)
		result = str;
	return ((char*)result);
}
