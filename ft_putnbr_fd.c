/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:42:45 by pfelipa           #+#    #+#             */
/*   Updated: 2020/09/02 18:56:32 by pfelipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static long	ft_div(long n)
{
	long mag;
	long res;

	mag = 0;
	while (n > 0)
	{
		n /= 10;
		mag++;
	}
	res = 1;
	while (mag-- > 1)
		res *= 10;
	return (res);
}

void		ft_putnbr_fd(int n, int fd)
{
	long d;
	long r;

	r = (long)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		r *= -1;
	}
	d = ft_div(r);
	while (r >= 0)
	{
		ft_putchar_fd(r / d + '0', fd);
		r -= (r / d) * d;
		d /= 10;
	}
}
