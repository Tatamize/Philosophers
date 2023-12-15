/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 07:49:10 by kito          #+#    #+#                 */
/*   Updated: 2020/11/29 18:44:02 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	st_unsigned(int num, int fd)
{
	if (num == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (-1);
	}
	else if (num == 0)
	{
		write(fd, "0", 1);
		return (-1);
	}
	else if (num < 0)
	{
		write(fd, "-", 1);
		num = num * -1;
	}
	return (num);
}

static int	st_ifzero(int digit, int fd)
{
	write(fd, "0", 1);
	digit = digit / 10;
	return (digit);
}

static int	st_printn(int num_pre, int num, int fd, int digit)
{
	char	number;

	number = num + '0';
	write(fd, &number, 1);
	return (num_pre - (num * digit));
}

static void	st_printzero(int fd, int num, int digit)
{
	if (num == 0 && digit >= 10)
	{
		while (digit > 1)
		{
			write(fd, "0", 1);
			digit = digit / 10;
		}
	}
	else
		return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	int		num;
	int		digit;
	int		num_pre;

	num = st_unsigned(n, fd);
	if (num == -1)
		return ;
	digit = 1;
	while (num > 0)
	{
		num_pre = num;
		if (num < digit / 10)
			digit = st_ifzero(digit, fd);
		else
		{
			digit = 1;
			while (num > 9)
			{
				num = num / 10;
				digit = digit * 10;
			}
			num = st_printn(num_pre, num, fd, digit);
			st_printzero(fd, num, digit);
		}
	}
}
