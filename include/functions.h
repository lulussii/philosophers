/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:34:43 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/16 16:32:07 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "all.h"

/* ----- ERRORS.C ----- */
void	ft_error(char *str, t_all *all);
void	free_all(t_all *all);

/* ----- INITS.C ----- */
void	init_forks(t_all *all);
void	init_philos(t_all *all);
void	allocate_ressources(t_all *all);

/* ----- PARSING.C ----- */
void	init_struct(int argc, char **argv, t_all *all);
void	check_values(t_all *all);
void	check_args(int argc, char **argv, t_all *all);

/* ----- ROUTINE.C ----- */
void	time_to_think(t_philo *philos);
void	time_to_sleep(t_philo *philos);
void	put_forks(t_philo *philos);
void	time_to_eat(t_philo *philos);
void	take_forks(t_philo *philos);

/* ----- SIMULATION.C ----- */
void	*check_last_meal(void *arg);
void	*routine(void *arg);
void	start_simulation(t_all *all);

/* ----- UTILS.C ----- */
int		ft_digit(char *str);
void	ft_putstr(char *str);
long	ft_atoi(char *str);
long	time_diff_ms(struct timeval t1);
void	safe_print(t_philo *philos, char *task);

#endif