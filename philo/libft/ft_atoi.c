/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 09:59:24 by kito          #+#    #+#                 */
/*   Updated: 2022/02/11 14:26:59 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	st_c_space(const char *str2)
{
	int	j;

	j = 0;
	while (str2[j] == ' ' || str2[j] == '\t' || str2[j] == '\v'\
			|| str2[j] == '\f' || str2[j] == '\r' || str2[j] == '\n')
		j++;
	return (j);
}

static int	st_c_zero(const char *str3, int ii)
{
	int	k;

	k = ii;
	while (str3[k] == '0')
		k++;
	return (k);
}

static long long int	st_c_value(const char *str, int i, int minus)
{
	long long	max_l;
	long long	value;

	max_l = 9223372036854775807;
	value = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (value > (max_l / 10) || (value == (max_l / 10) && str[i] - '0' > 7))
			return (-1 * (minus + 1) / 2);
		value = (10 * value) + (str[i] - 48);
		i++;
	}
	if (str[i] == '\0')
		return (value);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	value;
	int			minus;

	i = 0;
	value = 0;
	minus = 1;
	if (str[0] == '\0')
		return (0);
	i = st_c_space(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	i = st_c_zero(str, i);
	if (str[i] < 48 || str[i] > 57)
		return (0);
	value = st_c_value(str, i, minus);
	return (value * minus);
}
