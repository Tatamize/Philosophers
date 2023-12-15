/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_setdata.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 13:06:05 by kito          #+#    #+#                 */
/*   Updated: 2022/02/11 13:06:54 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_set_data(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (ERROR_RETURN);
	data->num_p = ft_atoi(argv[1]);
	if (data->num_p <= 0)
		return (ERROR_RETURN);
	data->t_die = ft_atoi(argv[2]);
	if (data->t_die <= 0)
		return (ERROR_RETURN);
	data->t_eat = ft_atoi(argv[3]);
	if (data->t_eat <= 0)
		return (ERROR_RETURN);
	data->t_sleep = ft_atoi(argv[4]);
	if (data->t_sleep <= 0)
		return (ERROR_RETURN);
	if (argc == 6)
	{
		data->t_to_eat = ft_atoi(argv[5]);
		if (data->t_to_eat <= 0)
			return (ERROR_RETURN);
	}
	else
		data->t_to_eat = -1;
	data->dead = 0;
	return (0);
}

void	ft_addlink_last(t_philo *p_head, t_philo *p_new)
{
	t_philo	*temp;

	temp = p_head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}	
	temp->next = p_new;
}

t_philo	*ft_set_p_data(t_philo *p_head, t_data *data)
{
	int		i;
	t_philo	*p_new;

	i = 1;
	p_new = NULL;
	while (i <= data->num_p)
	{
		p_new = malloc(sizeof(t_philo));
		if (p_new == NULL)
			return (ft_free_p_data(p_head));
		p_new->num = i;
		p_new->data = data;
		p_new->p_ate = 0;
		p_new->fork = 0;
		p_new->next = NULL;
		if (i == 1)
			p_head = p_new;
		else
			ft_addlink_last(p_head, p_new);
		i++;
	}
	p_new->next = p_head;
	return (p_head);
}
