/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:42:51 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/15 17:50:13 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

# include "data.h"
# include "philo.h"

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
}						t_all;

#endif