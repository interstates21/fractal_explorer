/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 13:45:31 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/10/29 15:02:04 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	nlen;

	i = 0;
	nlen = len;
	if (*little == 0)
		return ((char*)big);
	while (*big != 0 && len > 0)
	{
		if (*big == *little)
		{
			nlen = len;
			while (big[i] == little[i] && big[i] != 0 && len-- > 0)
				i++;
			if (little[i] == 0)
				return ((char*)big);
			i = 0;
			len = nlen;
		}
		big++;
		len--;
	}
	return (NULL);
}
