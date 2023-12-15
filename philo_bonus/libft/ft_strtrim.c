/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/09 15:44:21 by kito          #+#    #+#                 */
/*   Updated: 2020/11/17 19:52:14 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_checkstr(char c, char const *source)
{
	int	i;

	i = 0;
	while (source[i] != '\0')
	{
		if (c == source[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (s == NULL || set == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	k = 0;
	while (st_checkstr(s[i], set) != 0 && i < j)
		i++;
	while (st_checkstr(s[j - 1], set) != 0 && j > 0 && i != j)
		j--;
	str = malloc(sizeof(char) * (j - i + 1));
	if (!str)
		return (NULL);
	while (k < (j - i))
	{
		str[k] = s[i + k];
		k++;
	}
	str[k] = '\0';
	return (str);
}
