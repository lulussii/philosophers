/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:42:51 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/14 13:53:09 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_H
# define ALL_H

#include "philo.h"
#include "data.h"

typedef struct s_philo t_philo;

typedef struct s_all
{
	struct timeval	start_time;
	t_data			*data;
	t_philo			*philos;
	pthread_t		*threads;
	pthread_mutex_t	*forks;
}				t_all;

#endif