/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 20:18:18 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/07 17:41:53 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	char	*ret;
	int		length;

	if (s == NULL || f == NULL)
		return (NULL);
	length = ft_strlen(s);
	result = (char*)malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	ret = result;
	while (*s != 0)
	{
		*result = f(*s);
		s++;
		result++;
	}
	*result = 0;
	return (ret);
}
