/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 00:02:43 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/08 17:51:11 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(char const *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static char	*copy_word(char const *str, char c)
{
	char	*word;
	int		len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	word[len] = '\0';
	while (len > 0)
	{
		len--;
		word[len] = str[len];
	}
	return (word);
}

static int	fill_words(char **res, char const *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			res[i] = copy_word(str, c);
			if (!res[i])
				return (0);
			i++;
			while (*str && *str != c)
				str++;
		}
	}
	res[i] = NULL;
	return (1);
}

char	**ft_split(char const *str, char c)
{
	char	**res;
	int		i;

	res = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!res)
		return (NULL);
	if (!fill_words(res, str, c))
	{
		i = 0;
		while (res[i])
		{
			free(res[i]);
			i++;
		}
		free(res);
		return (NULL);
	}
	return (res);
}
