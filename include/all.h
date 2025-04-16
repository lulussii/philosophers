/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:42:51 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/16 16:24:58 by lserodon         ###   ########.fr       */
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
	t_data				*data;
	t_philo				*philos;
	pthread_t			*threads;
	pthread_t			monitor;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
}						t_all;

#endif