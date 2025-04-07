/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:04:24 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/07 16:58:20 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_error(char *str, t_all *all)
{
	ft_putstr(str);
	free(all);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (0);
	check_args(argc, argv, all);
}
