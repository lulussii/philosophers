/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:05:02 by lserodon          #+#    #+#             */
/*   Updated: 2025/05/12 10:30:40 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_all	t_all;

typedef struct s_philo
{
	int					id;
	int					meal_count;
	int					forks[2];
	pthread_mutex_t		*mutex_right_fork;
	pthread_mutex_t		*mutex_left_fork;
	pthread_mutex_t		*mutex_meal;
	struct timeval		last_meal;
	t_data				*data;
	t_all				*all;
}						t_philo;

#endif