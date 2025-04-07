/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:56:16 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/07 16:50:13 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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

int	ft_atoi(char *str)
{
	int	i;
	int	temp;
	int	sign;

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
	return (temp * sign);
}
