/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:08:32 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/15 20:58:05 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	f_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	int		len;
	int		space_count;
	char	*ret;

	if (s == NULL)
		return (NULL);
	space_count = 0;
	while (f_is_space(*s))
		s++;
	len = ft_strlen(s);
	if (len == 0)
	{
		ret = (char*)malloc(sizeof(char));
		ret[0] = 0;
		return (ret);
	}
	while (f_is_space(*(s + len - space_count - 1)))
		space_count++;
	ret = ft_strsub(s, 0, len - space_count);
	return (ret);
}
