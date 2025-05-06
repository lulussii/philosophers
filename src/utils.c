/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:56:16 by lserodon          #+#    #+#             */
/*   Updated: 2025/05/05 10:55:37 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <limits.h>
#include <unistd.h>
#include <stdio.h>

int	ft_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

long	ft_atoi(char *str)
{
	int		i;
	long	temp;
	int		sign;

	i = 0;
	temp = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || ((str[i] == ' ') && str[i]))
		i++;
	while ((str[i] == '-' || str[i] == '+') && str[i])
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		else if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		temp = temp * 10 + str[i] - '0';
		i++;
	}
	if (temp > INT_MAX || temp < INT_MIN)
		return (-1);
	return (temp * sign);
}

long	safe_atoi(char *str, t_all *all)
{
	long	res;

	res = ft_atoi(str);
	if (res == -1)
		ft_error("Error : Invalid integer\n", all);
	return (res);
}
