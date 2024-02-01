/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:56:13 by nfradet           #+#    #+#             */
/*   Updated: 2024/02/01 01:53:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv) || init_args(&data, argv))
		return (EXIT_FAILURE);
	printf("number of philo: %d\n", data.nb_philo);
	printf("time to die: %d\n", data.time_die);
	printf("time to eat: %d\n", data.time_eat);
	printf("time to sleep: %d\n", data.time_sleep);
	printf("must eat: %d\n", data.must_eat);
}
