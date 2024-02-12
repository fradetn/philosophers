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
	if (data != NULL)
	{
		if (data->philos != NULL)
			free(data->philos);
		else if (data->mutex_fork != NULL)
			free(data->mutex_fork);
	}
	write(STDERR_FILENO, "Error: ", 7);
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
	write(STDERR_FILENO, "\n", 1);
	return (EXIT_FAILURE);
}
