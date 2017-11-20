/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 01:29:08 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/14 05:35:06 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char			check_value(const char *str)
{
	long int	nb;

	nb = ft_atoi_long(str);
	if (nb < 0 || nb > 2147483647)
		return (0);
	return (1);
}

void	init_struct(t_env *e)
{
	e->ants = 0;
	e->args = 0;
	e->room = NULL;
	e->nb_room = 0;
	e->ind = 0;
}
