/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/02 13:35:02 by kito          #+#    #+#                 */
/*   Updated: 2020/11/03 19:27:16 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	int		i;
	int		j;

	cc = (char)c;
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			j = i;
		i++;
	}
	if (c == '\0' && s[i] == '\0')
		return ((char *)s + i);
	else if ((s[i] == '\0' && j != 0) || (s[0] == cc && j == 0))
		return ((char *)s + j);
	else
		return (NULL);
}
