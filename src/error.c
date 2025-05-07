/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserodon <lserodon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:57:16 by lserodon          #+#    #+#             */
/*   Updated: 2025/05/07 14:41:25 by lserodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"
#include "functions.h"
#include <stdlib.h>

void	ft_error(char *str, t_all *all)
{
	ft_putstr(str);
	cleanup_all_resources(all);
	exit(1);
}
