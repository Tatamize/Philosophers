/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 09:04:32 by kito          #+#    #+#                 */
/*   Updated: 2020/11/24 17:05:18 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_irregular(void *s, size_t n)
{
	if (n == 0)
		return (0);
	if (ft_strlen(s) >= n)
		return (0);
	else
		return (1);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	l_dst;
	size_t	l_src;
	size_t	i;
	char	*newdst;

	l_src = ft_strlen((char *)src);
	if (st_irregular(dst, dstsize) == 0)
		return (l_src + dstsize);
	l_dst = ft_strlen(dst);
	i = 0;
	newdst = dst;
	while (l_dst < (dstsize - 1))
	{
		newdst[l_dst] = src[i];
		if (src[i] == '\0')
			return (l_dst - i + l_src);
		l_dst++;
		i++;
	}
	newdst[l_dst] = '\0';
	return (l_dst - i + l_src);
}
