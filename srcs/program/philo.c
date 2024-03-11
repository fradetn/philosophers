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

void	*routine_thread(void *arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)arg;
	if (philo->data->nb_philo == 1)
		return (one_philo_case(philo));
	if (philo->id % 2 == 0)
		ft_sleep(philo->data->time_die / 3);
	while (should_end(philo->data) != 1)
	{
		eat(philo);
		sleep_n_think(philo);
		i++;
	}
	return (NULL);
}
