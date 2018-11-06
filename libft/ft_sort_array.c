/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:11:47 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/14 19:12:29 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_array(int *array, int length)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < length - 1)
	{
		j = i;
		while (j < length - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
