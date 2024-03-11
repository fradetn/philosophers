/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:25:09 by marvin            #+#    #+#             */
/*   Updated: 2024/02/01 01:25:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count])
	{
		count++;
	}
	return (count);
}

int	get_time_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return(handle_error(NULL, TIME_OF_DAY_ERR));
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	get_duration(int start_time)
{
	return (get_time_ms() - start_time);
}

void	print_mutex(char *msg, t_philo *ph, pthread_mutex_t *mutex)
{
	t_data *d;

	d = ph->data;
	if (should_end(d) != 1)
	{
		pthread_mutex_lock(mutex);
		printf("%d %d %s\n", get_duration(d->start_time), ph->id + 1, msg);
		pthread_mutex_unlock(mutex);
	}
}

void	ft_sleep(int ms)
{
	int	time;

	time = get_time_ms();
	usleep(ms * 900);
	while (get_time_ms() < time + ms)
		usleep(ms * 5);
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