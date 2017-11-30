/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 01:29:08 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/30 01:05:19 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_error(char *str, char flag)
{
	if (flag == 1)
		perror(str);
	else
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	exit(0);
}

char	check_value(const char *str)
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
	e->buff = NULL;
	e->str = NULL;
	e->args = 0;
	e->start = 0;
	e->end = 0;
	e->ind = 0;
	e->matrix = NULL;
	e->nb_room = 0;
	e->path = NULL;
	e->max_path = 0;
	e->nb_paths = 0;
	e->start_id = 0;
	e->end_id = 0;
	e->room = NULL;
}
