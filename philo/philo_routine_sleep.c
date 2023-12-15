/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_routine_sleep.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 13:08:25 by kito          #+#    #+#                 */
/*   Updated: 2022/02/23 07:15:49 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_sleep(t_philo *p)
{
	struct timeval	now;

	while (1)
	{
		usleep(500);
		gettimeofday(&now, NULL);
		pthread_mutex_lock(&p->data->gmutex);
		if (ft_diff(&p->lastmeal, &now) >= (p->data->t_eat + p->data->t_sleep))
		{
			pthread_mutex_unlock(&p->data->gmutex);
			return (0);
		}
		if (ft_diff(&p->lastmeal, &now) >= p->data->t_die)
		{
			if (p->data->dead == 0)
				ft_ts_write(ft_diff(&p->data->c_start, &now), p->num, "died\n");
			p->data->dead = p->num;
			return (ft_gmu_unlock_return_dead(p));
		}
		if (p->data->dead != 0)
			return (ft_gmu_unlock_return_dead(p));
		pthread_mutex_unlock(&p->data->gmutex);
	}
}

int	ft_philo_start_sleep(t_philo *p)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(&p->data->gmutex);
	if (p->data->dead == 0)
		ft_ts_write(ft_diff(&p->data->c_start, &now), p->num, "is sleeping\n");
	else
		return (ft_gmu_unlock_return_dead(p));
	pthread_mutex_unlock(&p->data->gmutex);
	if (ft_philo_sleep(p) != 0)
		return (ft_gmu_unlock_return_dead(p));
	return (0);
}
