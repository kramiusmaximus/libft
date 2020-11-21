/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfelipa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:42:45 by pfelipa           #+#    #+#             */
/*   Updated: 2020/09/02 18:56:32 by pfelipa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char		*ptrdst;
	const unsigned char	*ptrsrc;
	unsigned char		k;

	if (!dst && !src)
		return (NULL);
	ptrdst = dst;
	ptrsrc = src;
	k = (unsigned char)c;
	while (len-- > 0)
	{
		*ptrdst++ = *ptrsrc++;
		if (*(ptrsrc - 1) == k)
			return (ptrdst);
	}
	return (NULL);
}
