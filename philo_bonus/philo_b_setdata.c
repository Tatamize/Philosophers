/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_b_setdata.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 09:37:27 by kito          #+#    #+#                 */
/*   Updated: 2022/02/16 09:38:37 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	return (0);
}

t_philo	*ft_free_p_data(t_philo *p_head)
{
	t_philo	*temp;
	t_philo	*current;

	current = p_head;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	return (NULL);
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
		p_new->pid = 1;
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

int	ft_free_p_data_i(t_philo *p_head, int i)
{
	t_philo	*temp;
	t_philo	*current;

	current = p_head;
	while (i)
	{
		temp = current->next;
		free(current);
		current = temp;
		i--;
	}
	return (0);
}

int	ft_error_clear(char *txt, t_philo *p_head, int i)
{
	ft_free_p_data_i(p_head, i);
	write(2, txt, ft_strlen(txt));
	return (ERROR_RETURN);
}
