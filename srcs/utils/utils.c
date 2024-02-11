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

int	get_time_millisec(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return(handle_error(TIME_OF_DAY_ERR));
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
