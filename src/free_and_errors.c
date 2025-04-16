/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:16:03 by lserodon          #+#    #+#             */
/*   Updated: 2025/04/16 15:57:53 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include "all.h"
#include <stdlib.h>

void	free_all(t_all *all)
{
	if (all->data)
		free(all->data);
	if (all->threads)
		free(all->threads);
	free(all);
}

void	ft_error(char *str, t_all *all)
{
	ft_putstr(str);
	free_all(all);
	exit(1);
}
