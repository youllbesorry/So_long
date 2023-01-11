/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfaure <bfaure@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:38:39 by bfaure            #+#    #+#             */
/*   Updated: 2022/11/22 11:53:46 by bfaure           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	n;

	n = 0;
	j = ft_strlen(src);
	if (dstsize <= 0)
		return (j);
	i = ft_strlen(dst);
	if (dstsize <= i)
		return (dstsize + j);
	if (dstsize < i)
		j += dstsize;
	else
		j += i;
	while ((src[n] && i < dstsize - 1) && n < j)
	{
		dst[i] = src[n];
		n++;
		i++;
	}
	dst[i] = '\0';
	return (j);
}
