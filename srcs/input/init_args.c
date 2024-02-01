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

int	init_args(t_data *data, char **args)
{
	data->nb_philo = ft_longatoi(args[1]);
	data->time_die = ft_longatoi(args[2]);
	data->time_eat = ft_longatoi(args[3]);
	data->time_sleep = ft_longatoi(args[4]);
	if (args[5] != NULL)
		data->must_eat = ft_longatoi(args[5]);
	else
		data->must_eat = -1;
	if (data->nb_philo == 0 || data->must_eat == 0)
		return (handle_error(INIT_ERR));
	return (0);
}
