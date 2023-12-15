/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 13:10:38 by kito          #+#    #+#                 */
/*   Updated: 2022/02/14 11:35:38 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*th_monitor(void *arg)
{
	t_data			*d;

	d = (t_data *)arg;
	while (1)
	{
		pthread_mutex_lock(&d->gmutex);
		if ((d->t_to_eat > 0 && ft_total_ate(d->p_head)) || d->dead != 0)
		{
			if (ft_total_ate(d->p_head))
				d->dead = d->num_p + 1;
			pthread_mutex_unlock(&d->gmutex);
			return (arg);
		}
		pthread_mutex_unlock(&d->gmutex);
		usleep(500);
	}
	return (arg);
}

void	*th_routine(void *arg)
{
	t_philo			*p;

	p = (t_philo *)arg;
	gettimeofday(&p->lastmeal, NULL);
	if (p->data->num_p == 1)
		return (ft_one_philo(p));
	while (1)
	{
		if (ft_philo_wait(p) != 0)
			return (arg);
		pthread_mutex_lock(&p->mutex);
		pthread_mutex_lock(&p->next->mutex);
		ft_philo_start_meal(p);
		if (ft_philo_eat(p) != 0)
			return (arg);
		pthread_mutex_unlock(&p->next->mutex);
		pthread_mutex_unlock(&p->mutex);
		if (ft_philo_start_sleep(p) != 0)
			return (arg);
		if (ft_philo_start_think(p) != 0)
			return (arg);
	}
	return (arg);
}

int	main(int argc, char **argv)
{
	t_philo		*p_head;
	t_data		data;
	pthread_t	monitor;

	p_head = NULL;
	if (ft_set_data(&data, argc, argv) < 0)
		return (ft_error("missing or incorrect argument\n"));
	p_head = ft_set_p_data(p_head, &data);
	if (p_head == NULL)
		return (ft_error("malloc for a thread failed.\n"));
	data.p_head = p_head;
	if (pthread_mutex_init(&data.gmutex, NULL) != 0)
		return (ft_error_clear("mutex_init failed.\n", p_head, data.num_p));
	if (gettimeofday(&data.c_start, NULL) != 0)
		return (ft_error_clear("gettimeofday failed.\n", p_head, data.num_p));
	if (pthread_create(&monitor, NULL, &th_monitor, &data) != 0)
		return (ft_error_clear("pthread_create failed.\n", p_head, data.num_p));
	if (ft_p_th_create(data.num_p, p_head) != 0)
		return (ft_error_clear("pthread_create failed.\n", p_head, data.num_p));
	if (pthread_join(monitor, NULL) != 0)
		return (ft_error_clear("pthread_join failed.\n", p_head, data.num_p));
	if (pthread_mutex_destroy(&data.gmutex) != 0)
		return (ft_error_clear("mutex_destroy failed.\n", p_head, data.num_p));
	ft_free_p_data_i(p_head, data.num_p);
	return (0);
}
