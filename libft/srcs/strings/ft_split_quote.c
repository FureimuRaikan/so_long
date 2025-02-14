/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:03:16 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/05 15:03:24 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char c, char quote)
{
	size_t	i;
	int		is_word;
	size_t	words_count;
	bool	is_in_quote;

	i = 0;
	is_word = 0;
	words_count = 0;
	is_in_quote = false;
	while (str[i])
	{
		if (str[i] == quote)
			is_in_quote = !is_in_quote;
		if (str[i] == c && !is_in_quote)
			is_word = 0;
		else if (!is_word)
		{
			is_word = 1;
			words_count++;
		}
		i++;
	}
	return (words_count);
}

static size_t	ft_word_len(const char *str, char c, char quote)
{
	size_t	i;
	size_t	size;
	bool	in_quote;

	i = 0;
	size = 0;
	in_quote = false;
	while (str[i])
	{
		if (str[i] == quote)
			in_quote = !in_quote;
		else if (!in_quote && str[i] == c)
			break ;
		size++;
		i++;
	}
	return (size);
}

static char	**write_split(char **array, const char *str, char c, char quote)
{
	size_t	i;
	size_t	word_len;
	size_t	word_count;

	i = 0;
	word_count = count_words(str, c, quote);
	while (i < word_count)
	{
		word_len = ft_word_len(str, c, quote);
		while (*str == c && *str != quote)
			str++;
		array[i] = (char *)ft_calloc(sizeof(char), word_len + 1);
		if (!array[i])
			return (ft_free_split(array), NULL);
		ft_strlcpy(array[i], str, word_len + 1);
		str += word_len + 1;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split_quote(char const *str, char c, char quote)
{
	char	**array;
	size_t	word_count;

	word_count = count_words(str, c, quote);
	if (!str)
		return (NULL);
	array = (char **)ft_calloc(sizeof(char *), (word_count + 1));
	if (!array)
		return (NULL);
	return (write_split(array, str, c, quote));
}
