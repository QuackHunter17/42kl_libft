/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 21:48:53 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/04 22:16:41 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ret_zero()
{
	char	*res;

	res = malloc(sizeof(char) * 2);
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

static int	calc_len(int n)
{
	int	len;
	long	num;

	len = 0;
	num = n;
	if (n < 0)
	{
		num = - n;
		len++;
	}
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int	len;
	long	num;
	char	*res;

	num = n;
	if (n == 0)
		return (ret_zero());
	if (n < 0)
		num = - n;
	len = calc_len(n);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n < 0)
		res[0] = '-';
	while (num > 0)
	{
		len--;
		res[len] = (num % 10) + '0';
		num = num / 10;
	}
	return (res);
}
