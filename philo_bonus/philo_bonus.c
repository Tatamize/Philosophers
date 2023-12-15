/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/13 12:39:15 by kito          #+#    #+#                 */
/*   Updated: 2022/02/16 11:27:42 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	pr_monitor(t_data *data)
{
	int		i;
	t_philo	*p_current;

	i = 0;
	p_current = data->p_head;
	while (i < data->num_p)
	{
		sem_wait(data->sem_eat);
		i++;
	}
	sem_wait(data->sem_print);
	exit (0);
}

void	ft_set_sem(t_data *data)
{
	int	pair_forks;

	pair_forks = data->num_p / 2;
	sem_unlink("forks_sem");
	data->sem_fork = sem_open("forks_sem", O_CREAT | O_EXCL, 0666, pair_forks);
	if (data->sem_fork == SEM_FAILED)
		exit (ft_error_clear("sem open failed.\n", data->p_head, data->num_p));
	sem_unlink("times_eat");
	data->sem_eat = sem_open("times_eat", O_CREAT | O_EXCL, 0666, 0);
	if (data->sem_eat == SEM_FAILED)
		exit (ft_error_clear("sem open failed.\n", data->p_head, data->num_p));
	sem_unlink("print_sem");
	data->sem_print = sem_open("print_sem", O_CREAT | O_EXCL, 0666, 1);
	if (data->sem_print == SEM_FAILED)
		exit (ft_error_clear("sem open failed.\n", data->p_head, data->num_p));
}

void	ft_fork_philo(t_philo *p_head)
{
	t_philo		*p_current;
	int			i;

	i = 0;
	p_current = p_head;
	while (i < p_head->data->num_p)
	{
		if (p_current->pid > 0)
			p_current->pid = fork();
		if (p_current->pid < 0)
			exit (ft_error_clear("pthread_join failed.\n", p_head, i - 1));
		if (p_current->pid == 0)
			pr_routine(p_current);
		if (p_current->pid > 0)
		{
			p_current = p_current->next;
			i++;
		}
	}	
}

void	ft_kill_philos(t_philo *p_head)
{
	t_philo		*p_current;
	int			i;

	i = 0;
	p_current = p_head;
	while (i < p_head->data->num_p)
	{
		kill(p_current->pid, SIGKILL);
		p_current = p_current->next;
		i++;
	}
	kill(p_head->data->monitor, SIGKILL);
}

int	main(int argc, char **argv)
{
	t_philo		*p_head;
	t_data		data;
	int			status;

	p_head = NULL;
	if (ft_set_data(&data, argc, argv) < 0)
		return (ft_error("missing or incorrect argument\n"));
	p_head = ft_set_p_data(p_head, &data);
	if (p_head == NULL)
		return (ft_error("malloc for a thread failed.\n"));
	data.p_head = p_head;
	if (gettimeofday(&data.c_start, NULL) != 0)
		return (ft_error_clear("gettimeofday failed.\n", p_head, data.num_p));
	ft_set_sem(&data);
	data.monitor = fork();
	if (data.monitor < 0)
		return (ft_error("making monitor process failed.\n"));
	if (data.monitor == 0)
		pr_monitor(&data);
	ft_fork_philo(p_head);
	waitpid(-1, &status, WUNTRACED);
	ft_kill_philos(p_head);
	ft_free_p_data_i(p_head, data.num_p);
	return (0);
}
