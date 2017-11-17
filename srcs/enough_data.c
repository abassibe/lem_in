/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enough_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:04:32 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/17 07:03:22 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void			enough_room(t_room *room)
{
	int		i;

	i = 0;
	while (room)
	{
		room = room->next;
		i++;
	}
	if (i < 2)
		ft_error("ERROR", 0);
}

char		verif_already_check(int ind, int i, int *path)
{
	int		j;

	j = -1;
	while (++j != ind)
		if (path[j] == i)
			return (1);
	return (0);
}

char		looking_for_path(t_env *e, char *str, int id, int id_end, int *path)
{
	int		i;

	i = 0;
	if (str[id_end] == '1')
	{
		path[e->ind] = id;
		return (1);
	}
	while (i != e->ind)
		i++;
	path[i] = id;
	e->ind++;
	i = -1;
	while (++i < e->nb_room)
		if (str[i] == '1' && !verif_already_check(e->ind, i, path) && looking_for_path(e, e->matrix[i], i, id_end, &*path))
			return (1);
	i = 0;
	while (i != e->ind)
		i++;
	path[i] = -1;
	e->ind--;
	return (0);
}

static void		existing_path(t_env *e, t_room *room)
{
	int		id_start;
	int		id_end;
	int		*path;
	int i = 0;

	if (!(path = (int *)ft_memalloc(sizeof(int) * e->nb_room)))
		ft_error("ERROR", 0);
	while (room->features != 's')
		room = room->next;
	id_start = room->id;
	e->room = room;
	while (room->features != 'e')
		room = room->next;
	id_end = room->id;
	if (!looking_for_path(e, e->matrix[id_start], id_start, id_end, &*path))
		ft_error("ERROR", 0);
	printf("Y'A UN PUTAIN DE PATH !!!!\n");
	while (i != e->nb_room)
	{
		printf("%d, ", path[i]);
		i++;
	}
	printf("\n");
}

void			enough_data(t_env *e)
{
	if (e->start != 2 || e->end != 2)
		ft_error("ERROR", 0);
	enough_room(e->room);
	if (e->ants <= 0)
		ft_error("ERROR", 0);
	existing_path(e, e->room);
}
