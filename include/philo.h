/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:05:02 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/28 16:16:44 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_all	t_all;

typedef struct s_forks
{
	pthread_mutex_t	*first_mutex;
	pthread_mutex_t	*second_mutex;
	int				*first_fork;
	int				*second_fork;
}					t_forks;

typedef struct s_philo
{
	int					has_finished;
	int					id;
	int					is_dead;
	int					meal_count;
	pthread_mutex_t		*mutex_right_fork;
	int					*right_fork;
	pthread_mutex_t		*mutex_left_fork;
	int					*left_fork;
	struct timeval		last_meal;
	pthread_mutex_t		meal_mutex;
	t_forks				forks;
	t_data				*data;
	t_all				*all;
}						t_philo;

#endif