/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:55:50 by lserodon          #+#    #+#             */
/*   Updated: 2025/05/07 14:07:04 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>

void	init_data(int argc, char **argv, t_all *all)
{
	all->data = ft_malloc(sizeof(t_data), all);
	all->data->nbr_philos = safe_atoi(argv[1], all);
	all->data->time_to_die = safe_atoi(argv[2], all);
	all->data->philosopher_eat = safe_atoi(argv[3], all);
	all->data->philosopher_sleep = safe_atoi(argv[4], all);
	if (argc == 6)
		all->data->nbr_philosopher_eat = safe_atoi(argv[5], all);
	else
		all->data->nbr_philosopher_eat = -1;
}

void	check_values(t_all *all)
{
	if (!all->data->nbr_philos)
		ft_error("Error: The number of philosophers cannot be 0.", all);
	if (!all->data->time_to_die)
		ft_error("Error: The time to die cannot be 0.", all);
	if (!all->data->philosopher_eat)
		ft_error("Error: The time to eat cannot be 0.", all);
	if (!all->data->philosopher_sleep)
		ft_error("Error: The time to sleep cannot be 0.", all);
	if (!all->data->nbr_philosopher_eat)
		ft_error("Error: The number of meals cannot be 0.", all);
}

void	check_args(int argc, char **argv, t_all *all)
{
	int	i;

	i = 0;
	if (argc != 5 && argc != 6)
		ft_error("Error: Wrong number of arguments", all);
	while (++i < argc)
	{
		if (!ft_digit(argv[i]))
			ft_error("Error : Wrong type of arguments", all);
	}
	init_data(argc, argv, all);
	check_values(all);
}
