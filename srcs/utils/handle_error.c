/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:23:29 by marvin            #+#    #+#             */
/*   Updated: 2024/02/01 01:23:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	handle_error(t_data *data, char *err_msg)
{
	int	i;

	if (data != NULL)
	{
		if (data->philos != NULL)
			free(data->philos);
		if (data->mutex_fork != NULL)
		{
			i = 0;
			while (i < data->nb_philo)
				pthread_mutex_destroy(&(data->mutex_fork[i++]));
			free(data->mutex_fork);
			pthread_mutex_destroy(&(data->mutex_print));
			pthread_mutex_destroy(&(data->mutex_program));
			pthread_mutex_destroy(&(data->mutex_eating));
		}
	}
	if (err_msg != NULL)
	{
		write(STDERR_FILENO, "Error: ", 7);
		write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
		write(STDERR_FILENO, "\n", 1);
	}
	return (EXIT_FAILURE);
}
