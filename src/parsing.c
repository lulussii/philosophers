/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:55:50 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/18 08:59:18 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>

void	init_struct(int argc, char **argv, t_all *all)
{
	all->data = malloc(sizeof(t_data));
	if (!all->data)
		ft_error("Error\n", all);
	all->data->nbr_philos = ft_atoi(argv[1]);
	all->data->time_to_die = ft_atoi(argv[2]);
	all->data->time_to_eat = ft_atoi(argv[3]);
	all->data->time_to_sleep = ft_atoi(argv[4]);
	if (all->data->nbr_philos == -1 || all->data->time_to_die == -1
		|| all->data->time_to_eat == -1 || all->data->time_to_sleep == -1)
		ft_error("Error : Invalid integer format\n", all);
	if (argc == 6)
	{
		all->data->nbr_time_to_eat = ft_atoi(argv[5]);
		if (all->data->nbr_time_to_eat == -1)
			ft_error("Error : Invalid integer format\n", all);
	}
	else
		all->data->nbr_time_to_eat = -1;
}

void	check_values(t_all *all)
{
	if (!all->data->nbr_philos)
		ft_error("Error: The number of philosophers cannot be 0.\n", all);
	if (!all->data->time_to_die)
		ft_error("Error: The time to die cannot be 0.\n", all);
	if (!all->data->time_to_eat)
		ft_error("Error: The time to eat cannot be 0.\n", all);
	if (!all->data->time_to_sleep)
		ft_error("Error: The time to sleep cannot be 0.\n", all);
	if (!all->data->nbr_time_to_eat)
		ft_error("Error: The number of meals cannot be 0.\n", all);
}

void	check_args(int argc, char **argv, t_all *all)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		ft_error("Error: Wrong number of arguments\n", all);
	while (i < argc)
	{
		if (!ft_digit(argv[i]))
			ft_error("Error : Wrong type of arguments\n", all);
		i++;
	}
	init_struct(argc, argv, all);
	check_values(all);
}
