/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:05:02 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/08 16:51:20 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ----- LIBRARIES ----- */

#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/* ----- STRUCTURE ----- */

typedef struct s_data
{
	int			nbr_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nbr_time_to_eat;
}				t_data;

typedef struct s_philo
{
	int	id;
	t_data	*data;
}				t_philo;


typedef	struct s_all
{
	t_data		*data;
	t_philo		*philos;
	pthread_t	*threads;
}				t_all;

/* ----- UTILS.C ----- */

int		ft_digit(char *str);
void	ft_putstr(char *str);
int		ft_atoi(char *str);

/* ----- PARSING.C ----- */

void	check_args(int argc, char **argv, t_all *all);
void	init_struct(int argc, char **argv, t_all *all);
void	check_values(t_all *all);

/* ----- PHILO.C ----- */

void	ft_error(char *str, t_all *all);
