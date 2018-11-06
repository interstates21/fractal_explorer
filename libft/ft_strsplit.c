/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsyhuls <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:49:15 by rtsyhuls          #+#    #+#             */
/*   Updated: 2017/11/16 18:10:58 by rtsyhuls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_word_count(const char *s, char c)
{
	int	result;

	result = 0;
	while (*s++ != 0)
		if (*(s - 1) != c && (*s == c || *s == 0))
			result++;
	return (result);
}

static int	*ft_words_length(const char *s, char c, int words_count)
{
	int	*words_length;
	int	i;

	words_length = (int*)malloc(sizeof(int) * (words_count + 1));
	i = 0;
	if (words_length == NULL)
		return (NULL);
	*words_length = 0;
	while (*s != 0)
	{
		if (*s != c)
		{
			words_length[i]++;
			if (*(s + 1) == c)
				words_length[++i] = 0;
		}
		s++;
	}
	words_length[++i] = 0;
	return (words_length);
}

static void	ft_free_array(char **array)
{
	while (*array != 0)
	{
		free(*array);
		array++;
	}
	free(array);
}

static char	**init_array(const char *s, char c)
{
	char	**result;
	int		*words_length;
	int		i;
	int		w_count;

	i = 0;
	w_count = ft_word_count(s, c);
	words_length = ft_words_length(s, c, w_count);
	if (words_length == NULL)
		return (NULL);
	result = (char**)malloc(sizeof(char*) * (w_count + 1));
	if (result == NULL)
		return (NULL);
	while (i < w_count)
	{
		result[i] = (char*)malloc(sizeof(char) * (words_length[i] + 1));
		if (result[i] == NULL)
		{
			ft_free_array(result);
			return (NULL);
		}
		i++;
	}
	result[i] = 0;
	return (result);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	result = init_array(s, c);
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (*s != 0)
	{
		if (*s != c)
		{
			result[i][j++] = *s;
			if (*(s + 1) == c || *(s + 1) == 0)
			{
				result[i++][j] = 0;
				j = 0;
			}
		}
		s++;
	}
	return (result);
}
