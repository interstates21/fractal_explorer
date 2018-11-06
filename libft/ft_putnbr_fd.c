/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:38:27 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/05 16:39:04 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long m;
	char digit;

	if (n < 0)
		write(fd, "-", 1);
	m = n < 0 ? -(long)n : n;
	if (m > 9)
		ft_putnbr_fd(m / 10, fd);
	digit = (m % 10) + '0';
	write(fd, &digit, 1);
}
