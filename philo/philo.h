/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: kito <kito@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/04 08:25:31 by kito          #+#    #+#                 */
/*   Updated: 2022/02/14 11:27:39 by kito          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# define ERROR_RETURN -1
# define DEAD_RETURN -2

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
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
	int				dead;
	pthread_mutex_t	gmutex;
	struct s_philo	*p_head;
}	t_data;

struct s_philo
{
	int				num;
	t_data			*data;
	struct timeval	lastmeal;
	int				p_ate;
	int				fork;
	pthread_t		th;
	pthread_mutex_t	mutex;
	struct s_philo	*next;
};

//philo_util_common.c
int		ft_diff(struct timeval *s, struct timeval *e);
char	*ft_put_ui(unsigned int i, char *tx);
void	ft_ts_write(int ts, int who, char *text);
int		ft_total_ate(t_philo *p_head);

//philo_util_error.c
int		ft_error(char *txt);
t_philo	*ft_free_p_data(t_philo *p_head);
int		ft_free_p_data_i(t_philo *p_head, int i);
int		ft_error_clear(char *txt, t_philo *p_head, int i);

//philo_util_unlock.c
int		ft_mu3_unlock_return(t_philo *p);
int		ft_gmu_unlock_return_ok(t_philo *p);
int		ft_gmu_unlock_return_dead(t_philo *p);

//philo_setdata.c
int		ft_set_data(t_data *data, int argc, char **argv);
void	ft_addlink_last(t_philo *p_head, t_philo *p_new);
t_philo	*ft_set_p_data(t_philo *p_head, t_data *data);

//philo_routine_eat.c
int		ft_philo_wait(t_philo *p);
void	ft_philo_start_meal(t_philo *p);
int		ft_philo_eat(t_philo *p);

//philo_routine_sleep.c
int		ft_philo_sleep(t_philo *p);
int		ft_philo_start_sleep(t_philo *p);

//philo_routine_think.c
int		ft_philo_think(t_philo *p);
int		ft_philo_start_think(t_philo *p);

//philo_make_threads_routine.c
int		ft_mutex_init_n(int num, t_philo *p_head);
int		ft_pthread_create_n(int num, t_philo *p_head);
int		ft_pthread_join_destroy_n(int num, t_philo *p_head);
int		ft_p_th_create(int num, t_philo *p_head);
void	*ft_one_philo(t_philo *p);

//philo.c
void	*th_monitor(void *arg);
void	*th_routine(void *arg);
int		main(int argc, char **argv);

#endif
