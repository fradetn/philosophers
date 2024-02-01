/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:56:53 by nfradet           #+#    #+#             */
/*   Updated: 2024/02/01 01:48:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>

# define INVALID_ARGS_ERR "Invalid arguments"
# define INIT_ERR "nb_of_philosophers and must_eat_times must be bigger than 0"

typedef struct s_data
{
	int	nb_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	must_eat;
}	t_data;

/* Utils */
long int	ft_longatoi(const char *str);
size_t		ft_strlen(const char *s);
int			handle_error(char *err_msg);

/* Input */
int			check_args(int argc, char **argv);
int			init_args(t_data *data, char **args);
#endif