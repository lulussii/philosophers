/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:56:16 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/18 14:22:33 by lulussi          ###   ########.fr       */
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

long	time_diff_ms(struct timeval t1)
{
	long			milliseconds;
	struct timeval	actual;

	gettimeofday(&actual, NULL);
	milliseconds = ((actual.tv_sec * 1000 + actual.tv_usec / 1000) - (t1.tv_sec
				* 1000 + t1.tv_usec / 1000));
	return (milliseconds);
}

void	safe_print(t_philo *philos, char *task)
{
	pthread_mutex_lock(&philos->all->print);
	pthread_mutex_lock(&philos->all->simulation);
	if (philos->all->simulation_active)
		printf("%li %i %s\n", time_diff_ms(philos->all->start_time), philos->id,
			task);
	pthread_mutex_unlock(&philos->all->simulation);
	pthread_mutex_unlock(&philos->all->print);
}
