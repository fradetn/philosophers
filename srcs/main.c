/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:56:13 by nfradet           #+#    #+#             */
/*   Updated: 2024/02/12 17:13:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv) || init_data(&data, argv))
		return (EXIT_FAILURE);

	
	// printf("number of philo: %d\n", data.nb_philo);
	// printf("time to die: %d\n", data.time_die);
	// printf("time to eat: %d\n", data.time_eat);
	// printf("time to sleep: %d\n", data.time_sleep);
	// printf("must eat: %d\n", data.must_eat);

	// int i = 0;
	// while (i < data.nb_philo)
	// {
	// 	printf("philo: %d\n", data.philos[i].id);
	// 	printf("left fork: %d\n", data.philos[i].fork.l);
	// 	printf("right fork: %d\n\n", data.philos[i].fork.r);
	// 	i++;
	// }
}
