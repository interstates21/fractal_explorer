/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 12:58:18 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/10/29 13:21:27 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *big, const char *little)
{
	int	i;

	i = 0;
	if (*little == 0)
		return ((char*)big);
	while (*big != 0)
	{
		if (*big == *little)
		{
			while (big[i] == little[i] && big[i] != 0)
				i++;
			if (little[i] == 0)
				return ((char*)big);
			i = 0;
		}
		big++;
	}
	return (NULL);
}
