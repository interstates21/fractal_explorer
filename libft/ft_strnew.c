/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 09:25:08 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/10/28 09:25:10 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char			*n_string;
	unsigned long	i;

	i = 0;
	n_string = (char*)malloc(sizeof(char) * (size + 1));
	if (n_string == NULL)
		return (NULL);
	while (i < size + 1)
		n_string[i++] = '\0';
	return (n_string);
}
