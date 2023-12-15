/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_make_threads_routine.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 13:09:42 by kito          #+#    #+#                 */
/*   Updated: 2022/02/23 07:04:47 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mutex_init_n(int num, t_philo *p_head)
{
	t_philo	*current;
	int		i;

	current = p_head;
	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&current->mutex, NULL) != 0)
			return (ERROR_RETURN);
		current = current->next;
		i++;
	}
	return (0);
}

int	ft_pthread_create_n(int num, t_philo *p_head)
{
	t_philo	*current;
	int		i;

	current = p_head;
	i = 0;
	while (i < num)
	{
		if (pthread_create(&current->th, NULL, &th_routine, current) != 0)
		{
			current = p_head;
			i--;
			while (i)
			{
				pthread_join(current->th, NULL);
				current = current->next;
				i--;
			}
			p_head->data->dead = ERROR_RETURN;
			return (ERROR_RETURN);
		}
		current = current->next;
		i++;
		usleep(50);
	}
	return (0);
}

int	ft_pthread_join_destroy_n(int num, t_philo *p_head)
{
	t_philo	*current;
	int		i;

	current = p_head;
	i = 0;
	while (i < num)
	{
		if (pthread_join(current->th, NULL) != 0)
			return (ERROR_RETURN);
		current = current->next;
		i++;
	}
	i = 0;
	while (i < num)
	{
		if (pthread_mutex_destroy(&current->mutex) != 0)
			return (ERROR_RETURN);
		current = current->next;
		i++;
	}
	return (0);
}

int	ft_p_th_create(int num, t_philo *p_head)
{
	t_philo	*current;

	current = p_head;
	if (ft_mutex_init_n(num, p_head) != 0)
		return (ERROR_RETURN);
	if (ft_pthread_create_n(num, p_head) != 0)
		return (ERROR_RETURN);
	if (ft_pthread_join_destroy_n(num, p_head) != 0)
		return (ERROR_RETURN);
	return (0);
}

void	*ft_one_philo(t_philo *p)
{
	struct timeval	now;

	while (1)
	{
		usleep(500);
		gettimeofday(&now, NULL);
		pthread_mutex_lock(&p->data->gmutex);
		if (ft_diff(&p->lastmeal, &now) >= p->data->t_die)
		{
			ft_ts_write(ft_diff(&p->data->c_start, &now), p->num, "died\n");
			p->data->dead = 1;
			pthread_mutex_unlock(&p->data->gmutex);
			return ((void *)p);
		}
		pthread_mutex_unlock(&p->data->gmutex);
	}
	return ((void *)p);
}
