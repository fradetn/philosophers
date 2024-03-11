/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:56:53 by nfradet           #+#    #+#             */
/*   Updated: 2024/03/11 07:12:47 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>

# define INVALID_ARGS_ERR "Invalid arguments"
# define INIT_ERR "nb_of_philosophers and must_eat_times must be bigger than 0"
# define TIME_OF_DAY_ERR "gettimeofday failed"
# define MALLOC_ERR "malloc failed"
# define THREAD_INIT_ERR "failed to init a thread"
# define MUTEX_INIT_ERR "failed to init a mutex"
# define THREAD_JOIN_ERR "failed to join a thread"

struct	s_data;

typedef struct s_fork
{
	int	l;
	int	r;
}	t_fork;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	t_fork			fork;
	int				last_meal;
	int				*dead_flag;
	int				nb_meal;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				dead_flag;
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	int				start_time;
	t_philo			*philos;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	mutex_program;
	pthread_mutex_t	mutex_eating;
}	t_data;

/* Utils */
long int	ft_longatoi(const char *str);
size_t		ft_strlen(const char *s);
int			handle_error(t_data *data, char *err_msg);
int			get_duration(int start_time);
int			get_time_ms(void);
void		print_mutex(char *msg, t_philo *ph, pthread_mutex_t *mutex);
void		ft_sleep(int ms);
void		*one_philo_case(t_philo *philo);

/* Input */
int			check_args(int argc, char **argv);
int			init_data(t_data *data, char **args);
int			init_philos_mutex(t_data *data);
int			init_threads(t_data *data);

/* Program */
void		*routine_thread(void *arg);
void		take_fork(t_philo *ph);
void		drop_fork(t_philo *ph);
void		eat(t_philo *philo);
void		sleep_n_think(t_philo *philo);
void		watch_simulation(t_data *data);
int			should_end(t_data	*data);


#endif