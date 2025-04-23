/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 13:04:24 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/18 14:34:09 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
		return (0);
	memset(all, 0, sizeof(t_all));
	gettimeofday(&all->start_time, NULL);
	check_args(argc, argv, all);
	allocate_ressources(all);
	start_simulation(all);
	free_all(all);
}
