/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_util_common.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 13:02:22 by kito          #+#    #+#                 */
/*   Updated: 2022/02/11 13:03:59 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	ft_total_ate(t_philo *p_head)
{
	int		sum;
	int		i;
	t_philo	*current;

	sum = 0;
	i = 0;
	current = p_head;
	while (i < p_head->data->num_p)
	{
		sum += current->p_ate;
		current = current->next;
		i++;
	}
	if (sum >= p_head->data->num_p * p_head->data->t_to_eat)
		return (1);
	else
		return (0);
}
