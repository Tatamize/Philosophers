/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_util_unlock.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 13:05:19 by kito          #+#    #+#                 */
/*   Updated: 2022/02/11 13:05:53 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mu3_unlock_return(t_philo *p)
{
	pthread_mutex_unlock(&p->data->gmutex);
	pthread_mutex_unlock(&p->next->mutex);
	pthread_mutex_unlock(&p->mutex);
	return (DEAD_RETURN);
}

int	ft_gmu_unlock_return_ok(t_philo *p)
{
	pthread_mutex_unlock(&p->data->gmutex);
	return (0);
}

int	ft_gmu_unlock_return_dead(t_philo *p)
{
	pthread_mutex_unlock(&p->data->gmutex);
	return (DEAD_RETURN);
}
