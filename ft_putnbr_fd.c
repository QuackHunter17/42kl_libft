/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mousaidi <mousaidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:06:49 by mousaidi          #+#    #+#             */
/*   Updated: 2026/11/04 19:11:36 by mousaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	c;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = - num;
	}
	if (num >= 10)
		ft_putnbr_fd((int)(num / 10), fd);
	c = (num % 10) + '0';
	write(fd, &c, 1);
}
