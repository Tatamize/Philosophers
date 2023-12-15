/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_b_util.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 09:36:10 by kito          #+#    #+#                 */
/*   Updated: 2022/02/16 09:37:13 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_error(char *txt)
{
	write(2, txt, ft_strlen(txt));
	return (ERROR_RETURN);
}

int	ft_diff(struct timeval *s, struct timeval *e)
{
	int	diff;

	diff = 1000 * (e->tv_sec - s->tv_sec)
		+ (int)(1e-3 * (e->tv_usec - s->tv_usec));
	return (diff);
}

char	*ft_put_ui(unsigned int i, char *tx)
{
	char	c;

	if (i > 9)
		tx = ft_put_ui(i / 10, tx);
	c = i % 10 + '0';
	*tx = c;
	tx++;
	return (tx);
}

void	ft_ts_write(int ts, int who, char *text)
{
	char	tx[40];
	char	*tx_start;
	int		i;

	i = 0;
	tx_start = tx;
	tx_start = ft_put_ui(ts, tx);
	*tx_start = ' ';
	tx_start++;
	tx_start = ft_put_ui(who, tx_start);
	*tx_start = ' ';
	tx_start++;
	while (*text)
	{
		*tx_start = *text;
		tx_start++;
		text++;
	}
	*tx_start = '\0';
	write(1, tx, ft_strlen(tx));
}

void	ft_addlink_last(t_philo *p_head, t_philo *p_new)
{
	t_philo	*temp;

	temp = p_head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = p_new;
}
