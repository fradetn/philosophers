/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 20:47:47 by nfradet           #+#    #+#             */
/*   Updated: 2024/02/01 01:36:31 by marvin           ###   ########.fr       */
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
		return (handle_error(INVALID_ARGS_ERR));
	i = 1;
	while (argv[i])
	{
		if (is_valid_int(argv[i]) == 1)
			return (handle_error(INVALID_ARGS_ERR));
		i++;
	}
	return (0);
}
