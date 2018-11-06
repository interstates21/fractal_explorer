/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:57:47 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/02 13:58:21 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*rbegin;

	if (s == NULL)
		return (NULL);
	result = (char*)malloc(sizeof(char) * (len + 1));
	rbegin = result;
	if (result == NULL)
		return (NULL);
	s += start;
	while (len > 0)
	{
		*result++ = *s++;
		len--;
	}
	*result = 0;
	return (rbegin);
}
