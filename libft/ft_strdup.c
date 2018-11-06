/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 08:27:56 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/10/28 08:28:00 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		length;
	char	*result;
	char	*copy;

	length = ft_strlen(src) + 1;
	copy = (char*)malloc(sizeof(char) * length);
	if (copy == NULL)
		return (NULL);
	result = copy;
	while (*src != 0)
		*copy++ = *src++;
	*copy = 0;
	return (result);
}
