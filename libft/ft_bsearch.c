/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsearch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:20:00 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/14 19:20:02 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_bsearch(int *array, int length, int element)
{
	int	start;
	int	end;
	int	middle;

	start = 0;
	end = length - 1;
	while (start != end)
	{
		middle = (start + end) / 2;
		if (array[middle] == element)
			return (middle);
		else if (array[middle] > element)
			end = middle;
		else
			start = middle;
	}
	return (-1);
}
