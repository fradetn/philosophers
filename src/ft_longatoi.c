/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longatoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:28:03 by nfradet           #+#    #+#             */
/*   Updated: 2024/01/28 21:12:26 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_isnum2(int c)
{
	if ((c > 47 && c < 58))
	{
		return (2048);
	}
	return (0);
}

static int	ft_isspace2(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	else if (c == ' ' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static char	*ft_str_nospace2(char *str)
{
	while (ft_isspace2(*str) == 1)
	{
		str++;
	}
	return (str);
}

long int	ft_longatoi(const char *str)
{
	long int	res;
	long int	sign;

	res = 0;
	sign = 1;
	str = ft_str_nospace2((char *)str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isnum2(*str) != 0)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}
