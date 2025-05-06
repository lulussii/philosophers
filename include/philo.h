/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:05:02 by lserodon          #+#    #+#             */
/*   Updated: 2025/05/01 15:20:00 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_all	t_all;

typedef struct s_philo
{
	int					has_finished;
	int					id;
	int					is_dead;
	int					meal_count;
	pthread_mutex_t		*mutex_right_fork;
	int					forks[2];
	pthread_mutex_t		*mutex_left_fork;
	int					*left_fork;
	struct timeval		last_meal;
	pthread_mutex_t		mutex_meal;
	t_data				*data;
	t_all				*all;
}						t_philo;

#endif