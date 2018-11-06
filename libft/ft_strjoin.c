/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:08:19 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/07 16:31:17 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		length;
	char	*result;
	char	*ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	result = (char*)malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	ret = result;
	while (*s1 != 0)
		*result++ = *s1++;
	while (*s2 != 0)
		*result++ = *s2++;
	*result = 0;
	return (ret);
}
