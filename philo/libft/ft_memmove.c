/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 11:36:54 by kito          #+#    #+#                 */
/*   Updated: 2020/12/01 07:31:14 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_back(unsigned char *nd, unsigned char *ns, size_t l)
{
	while (l > 0)
	{
		nd[l - 1] = ns[l - 1];
		l--;
	}
}

static void	ft_put_front(unsigned char *nd, unsigned char *ns, size_t l)
{
	int	i;

	i = 0;
	while (i < (int)l)
	{
		nd[i] = ns[i];
		i++;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*newdist;
	unsigned char	*newsrc;

	newdist = (unsigned char *)dst;
	newsrc = (unsigned char *)src;
	if (len == 0 || dst == src)
		return (dst);
	if (src < dst && (src + len >= dst))
	{
		ft_put_back(newdist, newsrc, len);
	}
	else
	{
		ft_put_front(newdist, newsrc, len);
	}
	return (dst);
}
