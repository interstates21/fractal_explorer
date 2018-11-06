/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 09:17:17 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/10/30 09:17:18 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s1)
{
	int signum;
	int result;

	result = 0;
	signum = 1;
	while (ft_isspace(*s1))
		s1++;
	if (*s1 == '+' || *s1 == '-')
	{
		signum = *s1 == '-' ? -1 : 1;
		s1++;
	}
	while (ft_isdigit(*s1))
	{
		result = result * 10 + (*s1 - '0');
		s1++;
	}
	return (result * signum);
}
