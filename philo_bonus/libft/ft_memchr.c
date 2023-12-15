/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 12:33:39 by kito          #+#    #+#                 */
/*   Updated: 2020/11/24 14:54:45 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*news;
	unsigned char	newc;
	void			*ss;
	size_t			i;

	news = (unsigned char *)s;
	newc = (unsigned char)c;
	ss = (void *)s;
	i = 0;
	while (i < n)
	{
		if (news[i] == newc)
			return (ss + (unsigned char)i);
		i++;
	}
	return (NULL);
}
