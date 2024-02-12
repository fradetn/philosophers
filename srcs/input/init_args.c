/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:36:03 by marvin            #+#    #+#             */
/*   Updated: 2024/02/01 01:36:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_philos_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	data->mutex_fork = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (data->philos == NULL || data->mutex_fork == NULL)
		return(handle_error(data, MALLOC_ERR));
	while(i < data->nb_philo)
	{
		data->philos[i].id = i;
		data->philos[i].fork.l = (i + 1) % data->nb_philo;
		data->philos[i].fork.r = i;
		data->philos[i].last_meal = 0;
		data->philos[i].dead_flag = &(data->dead_flag);
		pthread_mutex_init(&data->mutex_fork[i], NULL);
		i++;
	}
	return (0);
}

int	init_data(t_data *data, char **args)
{
	data->nb_philo = ft_longatoi(args[1]);
	data->time_die = ft_longatoi(args[2]);
	data->time_eat = ft_longatoi(args[3]);
	data->time_sleep = ft_longatoi(args[4]);
	data->dead_flag = 0;
	data->philos = NULL;
	data->mutex_fork = NULL;
	if (args[5] != NULL)
		data->must_eat = ft_longatoi(args[5]);
	else
		data->must_eat = -1;
	if (data->nb_philo == 0 || data->must_eat == 0)
		return (handle_error(NULL, INIT_ERR));
	return (init_philos_mutex(data));
}
