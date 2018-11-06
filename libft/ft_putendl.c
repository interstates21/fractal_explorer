/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:28:33 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/05 15:32:09 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl(char const *s)
{
	int length;

	length = 0;
	if (s == NULL)
		return ;
	while (s[length] != 0)
		length++;
	write(1, s, length);
	write(1, "\n", 1);
}
