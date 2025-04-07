/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:05:02 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/07 16:58:53 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ----- LIBRARIES ----- */
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

/* ----- STRUCTURE ----- */

typedef struct s_all
{
	int	nbr_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_time_to_eat;
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
