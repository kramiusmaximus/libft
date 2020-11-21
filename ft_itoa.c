/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:42:45 by pfelipa           #+#    #+#             */
/*   Updated: 2020/09/02 18:56:32 by pfelipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*ft_revstring(char *s)
{
	int		len;
	int		i;
	char	temp;

	len = ft_strlen(s);
	i = 0;
	while (i < len / 2)
	{
		temp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = temp;
		i++;
	}
	return (s);
}

char		*ft_itoa(int n)
{
	char *res;
	char *ptr;
	int neg;
	long pos;
	char letter;

	if (!(res = ft_calloc(20, sizeof(char))))
		return (NULL);
	ptr = res;
	neg = (n < 0) ? 1 : 0;
	pos = (n < 0) ? -(long)n : (long)n;
	*ptr = '0';
	while (pos > 0)
	{
		letter = (char)(pos % 10) + '0';
		*ptr = letter;
		pos /= 10;
		ptr++;
	}
	if (neg)
		*ptr = '-';
	res = ft_revstring(res);
	return (res);
}
