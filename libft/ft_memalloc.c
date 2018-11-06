/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:49:54 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/07 16:19:58 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void			*result;
	unsigned long	i;

	i = 0;
	result = malloc(size);
	if (result == NULL)
		return (NULL);
	while (i < size)
	{
		((char*)result)[i] = 0;
		i++;
	}
	return (result);
}
