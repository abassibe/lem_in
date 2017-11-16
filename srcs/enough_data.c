/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enough_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 01:04:32 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/16 05:51:51 by abassibe         ###   ########.fr       */
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

static void		existing_path(t_room *room, int nb_room)
{
	int		id_start;
	int		id_end;
	char	path[nb_room];
	t_room	*tmp;

	tmp = room;
	while (tmp->features != 's')
		tmp = tmp->next;
	id_start = tmp->id;
	tmp = room;
	while (tmp->features != 'e')
		tmp = tmp->next;
	id_end = tmp->id;
}

void			enough_data(t_env *e)
{
	enough_room(e->room);
	if (e->ants <= 0)
		ft_error("ERROR", 0);
	if (e->start != 2 && e->end != 2)
		ft_error("ERROR", 0);
	existing_path(e->room, e->nb_room);
}
