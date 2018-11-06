/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 13:26:34 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/10/30 13:26:37 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	char	l;

	l = (char)c;
	return (c <= 'Z' && c >= 'A' ? c + 32 : c);
}