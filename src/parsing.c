/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:55:50 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/07 16:57:39 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

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

void	init_struct(int argc, char **argv, t_all *all)
{
	all->nbr_philos = ft_atoi(argv[1]);
	all->time_to_die = ft_atoi(argv[2]);
	all->time_to_eat = ft_atoi(argv[3]);
	all->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		all->nbr_time_to_eat = ft_atoi(argv[5]);
	else
		all->nbr_time_to_eat = -1;
}

void	check_values(t_all *all)
{
	if (!all->nbr_philos)
		ft_error("Error: The number of philosophers cannot be 0.\n", all);
	if (!all->time_to_die)
		ft_error("Error: The time to die cannot be 0.\n", all);
	if (!all->time_to_eat)
		ft_error("Error: The time to eat cannot be 0.\n", all);
	if (!all->time_to_sleep)
		ft_error("Error: The time to sleep cannot be 0.\n", all);
	if (!all->nbr_time_to_eat)
		ft_error("Error:  The number of times a philosopher must eat cannot be 0.\n",
			all);
}