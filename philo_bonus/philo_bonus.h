/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 09:14:12 by kito          #+#    #+#                 */
/*   Updated: 2022/02/16 11:16:50 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# define ERROR_RETURN -1

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <signal.h>
# include <time.h>
# include <semaphore.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int				num_p;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				t_to_eat;
	struct timeval	c_start;
	sem_t			*sem_fork;
	sem_t			*sem_eat;
	sem_t			*sem_print;
	pid_t			monitor;
	struct s_philo	*p_head;
}	t_data;

struct s_philo
{
	int				num;
	t_data			*data;
	struct timeval	lastmeal;
	int				p_ate;
	pid_t			pid;
	pthread_t		th;
	pthread_mutex_t	mutex;
	struct s_philo	*next;
};

//philo_b_util.c
int		ft_error(char *txt);
int		ft_diff(struct timeval *s, struct timeval *e);
char	*ft_put_ui(unsigned int i, char *tx);
void	ft_ts_write(int ts, int who, char *text);
void	ft_addlink_last(t_philo *p_head, t_philo *p_new);

//philo_b_setdata.c
int		ft_set_data(t_data *data, int argc, char **argv);
t_philo	*ft_free_p_data(t_philo *p_head);
t_philo	*ft_set_p_data(t_philo *p_head, t_data *data);
int		ft_free_p_data_i(t_philo *p_head, int i);
int		ft_error_clear(char *txt, t_philo *p_head, int i);

//philo_b_routine.c
void	*th_clock(void *arg);
int		ft_philo_eat(t_philo *p);
int		ft_philo_sleep(t_philo *p);
int		ft_philo_think(t_philo *p);
int		pr_routine(t_philo *p);

//philo_bonus.c
int		pr_monitor(t_data *data);
void	ft_set_sem(t_data *data);
void	ft_fork_philo(t_philo *p_head);
void	ft_kill_philos(t_philo *p_head);
int		main(int argc, char **argv);

#endif
