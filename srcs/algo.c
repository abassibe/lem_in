/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:05:48 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/30 02:38:41 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	get_max_path(t_env *e)
{
	int		i;
	int		tmp;

	i = -1;
	tmp = 0;
	while (++i < e->nb_room)
		if (e->matrix[e->start_id][i] == '1')
			e->max_path++;
	i = -1;
	while (++i < e->nb_room)
		if (e->matrix[e->end_id][i] == '1')
			tmp++;
	if (tmp > 0 && e->max_path > tmp)
		e->max_path = tmp;
	if (e->max_path > e->ants)
		e->max_path = e->ants;
}

void	reset_matrix(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < e->nb_room)
	{
		while (++j < e->nb_room)
			e->matrix[i][j] = 0;
		j = -1;
	}
}

void	all_in_one(t_env *e)
{
	int		i;

	i = -1;
	while (++i < e->ants)
		print_move(e, e->start_id, e->end_id);
	write(1, "\n", 1);
}

void	algo(t_env *e)
{
	int		i;
	int		**paths;
	int		ant_max;

	i = -1;
	ant_max = e->ants;
	free(e->path);
	if (!(e->bl = (int *)ft_memalloc((sizeof(int) * e->nb_room) + 1)))
		ft_error("ERROR", 1);
	while (++i < e->nb_room)
		e->bl[i] = -1;
	get_max_path(e);
	e->ind = 0;
	paths = get_path(e);
	reset_matrix(e);
	if (paths[0][1] == -1)
		all_in_one(e);
	else
		send_ants(e, paths, ant_max);
}
