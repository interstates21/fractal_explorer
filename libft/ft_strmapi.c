/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 20:24:02 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/07 16:24:14 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;
	int		length;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	length = ft_strlen(s);
	result = (char*)malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	while (i < length)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
