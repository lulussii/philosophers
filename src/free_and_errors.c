/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulussi <lulussi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:16:03 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/18 08:59:29 by lulussi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "all.h"
#include <stdlib.h>

void	free_all(t_all *all)
{
	if (all->threads)
		free(all->threads);
	if (all->forks)
		free(all->forks);
	if (all->data)
		free(all->data);
	if (all->philos)
		free(all->philos);
	free(all);
}

void	ft_error(char *str, t_all *all)
{
	ft_putstr(str);
	free_all(all);
	exit(1);
}
