/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:26:27 by nfradet           #+#    #+#             */
/*   Updated: 2024/03/11 09:44:17 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_fork(t_philo *ph)
{
	t_data	*data;

	data = ph->data;
	pthread_mutex_lock(&(data->mutex_fork[ph->fork.l]));
	print_mutex("has taken a fork", ph, &(data->mutex_print));
	pthread_mutex_lock(&(data->mutex_fork[ph->fork.r]));
	print_mutex("has taken a fork", ph, &(data->mutex_print));
}

void	drop_fork(t_philo *ph)
{
	t_data	*data;

	data = ph->data;
	pthread_mutex_unlock(&(data->mutex_fork[ph->fork.r]));
	pthread_mutex_unlock(&(data->mutex_fork[ph->fork.l]));
}

void	eat(t_philo *philo)
{
	t_data			*data;

	data = philo->data;
	take_fork(philo);
	pthread_mutex_lock(&(data->mutex_eating));
	pthread_mutex_lock(&(data->mutex_program));
	philo->nb_meal += 1;
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(&(data->mutex_program));
	print_mutex("is eating", philo, &(data->mutex_print));
	pthread_mutex_unlock(&(data->mutex_eating));
	ft_sleep(data->time_eat);
	drop_fork(philo);
}

void	sleep_n_think(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	print_mutex("is sleeping", philo, &(data->mutex_print));
	if (should_end(philo->data) != 1)
		ft_sleep(data->time_sleep);
	print_mutex("is thinking", philo, &(data->mutex_print));
}

void	*one_philo_case(t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->mutex_program));
	philo->last_meal = get_time_ms();
	pthread_mutex_unlock(&(philo->data->mutex_program));
	print_mutex("has taken a fork", philo, &(philo->data->mutex_print));
	ft_sleep(philo->data->time_die);
	return (NULL);
}
