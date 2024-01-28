/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:47:47 by nfradet           #+#    #+#             */
/*   Updated: 2024/01/28 21:29:20 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if ((c > 47 && c < 58))
		return (2048);
	return (0);
}

int	is_valid_int(char *val)
{
	int	i;

	if (ft_longatoi(val) > 2147483647)
		return (1);
	else if (ft_longatoi(val) < 0)
		return (1);
	i = 0;
	if (val[0] == '+')
		i++;
	while (val[i])
	{
		if (ft_isdigit(val[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	i = 1;
	while (argv[i])
	{
		if (is_valid_int(argv[i]) == 1)
		{
			printf("Invalid arguments type");
			return (1);
		}
		i++;
	}
	return (0);
}

void	extract_args(t_data *data, char **args)
{
	data->nb_philo = ft_longatoi(args[1]);
	data->time_die = ft_longatoi(args[2]);
	data->time_eat = ft_longatoi(args[3]);
	data->time_sleep = ft_longatoi(args[4]);
	if (args[5] != NULL)
		data->must_eat = ft_longatoi(args[5]);
	else
		data->must_eat = -1;
}
