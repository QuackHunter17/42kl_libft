/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 22:11:51 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/04 23:00:25 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static size_t	start(char const *s, char const *set)
{
	size_t	set_len;
	size_t	i;
	size_t	j;

	set_len = ft_strlen(set);
	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s[i] == set[j])
				break ;
			j++;
		}
		if (j == set_len)
			return (i);
		i++;
	}
	return (-1);
}

static size_t	end(char const *s, char const *set)
{
	size_t	set_len;
	size_t	i;
	size_t	j;

	set_len = ft_strlen(set);
	i = ft_strlen(s);
	if (i == 0)
		return (-1);
	i--;
	while (i > 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s[i] == set[j])
				break ;
			j++;
		}
		if (j == set_len)
			return (i);
		i--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	indexs[2];
	size_t	i;

	indexs[0] = start(s1, set);
	indexs[1] = end(s1, set);
	if (indexs[0] == -1 || indexs[1] == -1)
	{
		res = malloc(sizeof(char) * 1);
		if (res)
			*res = '\0';
		return (res);
	}
	res = malloc(sizeof(char) * (indexs[1] - indexs[0] + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (indexs[0] + i <= indexs[1])
	{
		res[i] = s1[indexs[0] + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
