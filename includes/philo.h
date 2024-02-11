/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:56:53 by nfradet           #+#    #+#             */
/*   Updated: 2024/02/11 19:18:12 by nfradet          ###   ########.fr       */
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

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	int			fork_used;
	int			last_meal;
	int			*dead_flag;	
}	t_philo;

typedef struct s_data
{
	int	dead_flag;
	int	nb_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	must_eat;
	t_philo	*philos;
}	t_data;

/* Utils */
long int	ft_longatoi(const char *str);
size_t		ft_strlen(const char *s);
int			handle_error(char *err_msg);

/* Input */
int			check_args(int argc, char **argv);
int			init_args(t_data *data, char **args);
#endif