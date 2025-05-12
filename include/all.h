/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:42:51 by lserodon          #+#    #+#             */
/*   Updated: 2025/05/08 19:15:36 by lserodon         ###   ########.fr       */
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
	int					*forks;
	int					max_meals;
	int					simulation_active;
	struct timeval		start_time;
	pthread_mutex_t		*mutex_forks;
	pthread_mutex_t		*mutex_meal;
	pthread_mutex_t		*mutex_max_meals;
	pthread_mutex_t		*print;
	pthread_mutex_t		*simulation;
	pthread_t			monitor;
	pthread_t			*threads;
	t_data				*data;
	t_philo				*philos;
}						t_all;

#endif