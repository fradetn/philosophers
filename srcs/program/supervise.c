/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 09:39:09 by nfradet           #+#    #+#             */
/*   Updated: 2024/03/11 09:46:24 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philo_dead(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (get_duration(philo->last_meal) > data->time_die)
	{
		*(philo->dead_flag) = 1;
		pthread_mutex_unlock(&(data->mutex_program));
		pthread_mutex_unlock(&(data->mutex_eating));
		pthread_mutex_lock(&(data->mutex_print));
		printf("%d %d is dead\n", get_duration(data->start_time), \
		philo->id + 1);
		pthread_mutex_unlock(&(data->mutex_print));
		return (1);
	}
	return (0);
}

int	watch_philo_life(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->mutex_eating));
	pthread_mutex_lock(&(data->mutex_program));
	if (is_philo_dead(philo) == 1)
		return (1);
	if (data->must_eat != -1)
	{
		if (get_satisfied(data) == data->nb_philo)
		{
			*(philo->dead_flag) = 1;
			pthread_mutex_unlock(&(data->mutex_program));
			pthread_mutex_unlock(&(data->mutex_eating));
			return (1);
		}
	}
	pthread_mutex_unlock(&(data->mutex_program));
	pthread_mutex_unlock(&(data->mutex_eating));
	return (0);
}

void	watch_simulation(t_data *data)
{
	int	i;

	while (should_end(data) != 1)
	{
		i = 0;
		while (i < data->nb_philo)
		{
			if (watch_philo_life(&(data->philos[i])) == 1)
				return ;
			i++;
		}
	}
}
