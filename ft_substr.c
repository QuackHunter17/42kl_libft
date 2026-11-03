/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 11:59:20 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/03 13:06:27 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*mem_alloc(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	actual_len;

	if (!s)
		return (NULL);

	if (start >= ft_strlen(s))
	{
		return (mem_alloc(s, start, 0));
	}
	actual_len = ft_strlen(s) - start;
	if (actual_len > len)
		actual_len = len;
	return (mem_alloc(s, start, actual_len));
}
