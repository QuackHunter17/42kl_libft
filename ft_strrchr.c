/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 11:46:55 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/08 14:11:49 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	if ((char) c == '\0')
		return ((char *) &s[s_len]);
	while (s_len > 0)
	{
		s_len--;
		if (s[s_len] == (char) c)
			return ((char *) &s[s_len]);
	}
	return (NULL);
}
