/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_routine_eat.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 13:07:31 by kito          #+#    #+#                 */
/*   Updated: 2022/02/17 13:26:55 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo_wait(t_philo *p)
{
	struct timeval	now;

	while (1)
	{
		usleep(200);
		gettimeofday(&now, NULL);
		pthread_mutex_lock(&p->data->gmutex);
		if (p->fork == 0 && p->next->fork == 0)
		{
			pthread_mutex_unlock(&p->data->gmutex);
			return (0);
		}
		if (ft_diff(&p->lastmeal, &now) >= p->data->t_die)
		{
			if (p->data->dead == 0)
				ft_ts_write(ft_diff(&p->data->c_start, &now), p->num, "died!\n");
			p->data->dead = p->num;
			return (ft_gmu_unlock_return_dead(p));
		}
		if (p->data->dead != 0)
			return (ft_gmu_unlock_return_dead(p));
		pthread_mutex_unlock(&p->data->gmutex);
	}
}

void	ft_philo_start_meal(t_philo *p)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&p->data->gmutex);
	gettimeofday(&p->lastmeal, NULL);
	p->fork = 1;
	p->next->fork = 1;
	i = ft_diff(&p->data->c_start, &p->lastmeal);
	if (p->data->dead == 0)
	{
		ft_ts_write(i, p->num, "has taken a fork\n");
		ft_ts_write(i, p->num, "has taken a fork\n");
		ft_ts_write(i, p->num, "is eating\n");
	}
	if (p->p_ate < p->data->t_to_eat)
		p->p_ate = p->p_ate + 1;
	if (p->data->t_to_eat > 0 && ft_total_ate(p))
		p->data->dead = p->num + 1;
	pthread_mutex_unlock(&p->data->gmutex);
}

int	ft_philo_eat(t_philo *p)
{
	struct timeval	now;

	while (1)
	{
		usleep(500);
		gettimeofday(&now, NULL);
		pthread_mutex_lock(&p->data->gmutex);
		if (ft_diff(&p->lastmeal, &now) >= p->data->t_eat)
		{
			p->fork = 0;
			p->next->fork = 0;
			pthread_mutex_unlock(&p->data->gmutex);
			return (0);
		}	
		if (ft_diff(&p->lastmeal, &now) >= p->data->t_die)
		{
			if (p->data->dead == 0)
				ft_ts_write(ft_diff(&p->data->c_start, &now), p->num, "died\n");
			p->data->dead = p->num;
			return (ft_mu3_unlock_return(p));
		}		
		if (p->data->dead != 0)
			return (ft_mu3_unlock_return(p));
		pthread_mutex_unlock(&p->data->gmutex);
	}
}
