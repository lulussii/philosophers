/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:42:51 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/23 12:16:08 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include "data.h"
# include "philo.h"
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo	t_philo;

typedef struct s_all
{
	struct timeval		start_time;
	int					simulation_active;
	pthread_mutex_t		simulation;
	int					max_meals;
	pthread_mutex_t		mutex_max_meals;
	pthread_t			*threads;
	pthread_t			monitor;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
	t_data				*data;
	t_philo				*philos;
}						t_all;

#endif