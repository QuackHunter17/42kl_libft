/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 18:58:45 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/01 21:30:39 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (d > s)
	{
		while (len > 0)
		{
			len--;
			d[len] = s[len];
		}

	}
	else
	{
		while (len > 0)
		{
			*d = *s;
			d++;
			s++;
			len--;
		}	
	}
	return (dest);
}
