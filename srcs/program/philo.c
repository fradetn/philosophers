/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:35:38 by nfradet           #+#    #+#             */
/*   Updated: 2024/02/28 09:35:38 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_satisfied(t_data *data)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < data->nb_philo)
	{
		if (data->philos[i].nb_meal >= data->must_eat)
			count++;
		i++;
	}
	return (count);
}

int	watch_philo_life(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->mutex_eating));
	pthread_mutex_lock(&(data->mutex_program));
	if (get_duration(philo->last_meal) > data->time_die)
	{
		*(philo->dead_flag) = 1;
		pthread_mutex_unlock(&(data->mutex_program));
		pthread_mutex_unlock(&(data->mutex_eating));
		pthread_mutex_lock(&(data->mutex_print));
		printf("%d %d is dead\n", get_duration(data->start_time), philo->id + 1);
		pthread_mutex_unlock(&(data->mutex_print));
		return 1;
	}
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

int	should_end(t_data	*data)
{
	pthread_mutex_lock(&(data->mutex_program));
	if (data->dead_flag == 1)
	{
		pthread_mutex_unlock(&(data->mutex_program));
		return (1);
	}
	pthread_mutex_unlock(&(data->mutex_program));
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

void	*routine_thread(void *arg)
{
	t_philo	*philo;
	int	i;

	i = 0;
	philo = (t_philo *)arg;
	if (philo->data->nb_philo == 1)
		return(one_philo_case(philo));
	if (philo->id % 2 == 0)
		ft_sleep(philo->data->time_die / 3);
	while (should_end(philo->data) != 1)
	{		
		eat(philo);
		sleep_n_think(philo);
		i++;
	}
	return NULL;
}
