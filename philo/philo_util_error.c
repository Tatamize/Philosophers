/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_util_error.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/11 13:04:18 by kito          #+#    #+#                 */
/*   Updated: 2022/02/11 13:05:00 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *txt)
{
	write(2, txt, ft_strlen(txt));
	return (ERROR_RETURN);
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
