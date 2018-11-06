/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 19:38:16 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/03 20:20:31 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int n)
{
	long	m;
	int		length;
	char	*result;
	long	signum;

	signum = n < 0 ? -1 : 1;
	m = n * signum;
	length = 1;
	while ((m = m / 10))
		length++;
	length = signum == -1 ? length + 1 : length;
	result = malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);
	result[length] = 0;
	m = n * signum;
	(m == 0) ? result[0] = '0' : 0;
	while (m > 0)
	{
		result[--length] = m % 10 + '0';
		m /= 10;
	}
	if (signum == -1)
		result[0] = '-';
	return (result);
}
