/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_b_routine.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 09:38:50 by kito          #+#    #+#                 */
/*   Updated: 2022/02/23 07:39:14 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*th_clock(void *arg)
{
	t_philo			*p;
	struct timeval	now;
	int				clock;

	p = (t_philo *)arg;
	pthread_mutex_lock(&p->mutex);
	gettimeofday(&p->lastmeal, NULL);
	pthread_mutex_unlock(&p->mutex);
	while (1)
	{	
		gettimeofday(&now, NULL);
		pthread_mutex_lock(&p->mutex);
		clock = ft_diff(&p->lastmeal, &now);
		pthread_mutex_unlock(&p->mutex);
		if (clock >= p->data->t_die)
		{
			sem_wait(p->data->sem_print);
			ft_ts_write(clock, p->num, "died\n");
			exit(0);
		}
		usleep(300);
	}	
	return (arg);
}

int	ft_philo_eat(t_philo *p)
{
	struct timeval	now;
	int				clock;

	pthread_mutex_lock(&p->mutex);
	gettimeofday(&p->lastmeal, NULL);
	pthread_mutex_unlock(&p->mutex);
	gettimeofday(&now, NULL);
	sem_wait(p->data->sem_print);
	ft_ts_write(ft_diff(&p->data->c_start, &now), p->num, "has taken a fork\n");
	ft_ts_write(ft_diff(&p->data->c_start, &now), p->num, "has taken a fork\n");
	ft_ts_write(ft_diff(&p->data->c_start, &now), p->num, "is eating\n");
	sem_post(p->data->sem_print);
	p->p_ate = p->p_ate + 1;
	if (p->p_ate == p->data->t_to_eat)
		sem_post(p->data->sem_eat);
	while (1)
	{
		gettimeofday(&now, NULL);
		pthread_mutex_lock(&p->mutex);
		clock = ft_diff(&p->lastmeal, &now);
		pthread_mutex_unlock(&p->mutex);
		if (clock >= p->data->t_eat)
			return (0);
		usleep(500);
	}
}

int	ft_philo_sleep(t_philo *p)
{
	struct timeval	now;
	int				clock;

	gettimeofday(&now, NULL);
	sem_wait(p->data->sem_print);
	ft_ts_write(ft_diff(&p->data->c_start, &now), p->num, "is sleeping\n");
	sem_post(p->data->sem_print);
	while (1)
	{
		gettimeofday(&now, NULL);
		pthread_mutex_lock(&p->mutex);
		clock = ft_diff(&p->lastmeal, &now);
		pthread_mutex_unlock(&p->mutex);
		if (clock >= (p->data->t_eat + p->data->t_sleep))
			return (0);
		usleep(500);
	}
}

int	ft_philo_think(t_philo *p)
{
	struct timeval	now;
	int				clock;
	int				think;

	gettimeofday(&now, NULL);
	sem_wait(p->data->sem_print);
	ft_ts_write(ft_diff(&p->data->c_start, &now), p->num, "is thinking\n");
	sem_post(p->data->sem_print);
	think = p->data->t_die - (p->data->t_eat);
	if (think <= p->data->t_eat + p->data->t_sleep)
		return (0);
	while (1)
	{
		gettimeofday(&now, NULL);
		pthread_mutex_lock(&p->mutex);
		clock = ft_diff(&p->lastmeal, &now);
		pthread_mutex_unlock(&p->mutex);
		if (clock >= think)
			return (0);
		usleep(500);
	}
}

int	pr_routine(t_philo *p)
{
	if (pthread_mutex_init(&p->mutex, NULL) != 0)
		exit (ft_error_clear("mutex_init failed.\n", p, p->data->num_p));
	if (pthread_create(&p->th, NULL, &th_clock, p) != 0)
		exit(ft_error_clear("thread create failed.\n", p, p->data->num_p));
	if (pthread_detach(p->th) != 0)
		exit(ft_error_clear("thread detach failed.\n", p, p->data->num_p));
	while (1)
	{
		sem_wait(p->data->sem_fork);
		ft_philo_eat(p);
		sem_post(p->data->sem_fork);
		ft_philo_sleep(p);
		ft_philo_think(p);
	}
	if (pthread_mutex_destroy(&p->mutex) != 0)
		exit (ft_error_clear("mutex_destroy failed.\n", p, p->data->num_p));
	exit (0);
}
