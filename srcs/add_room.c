/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 01:24:20 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/14 03:15:55 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		add_other_room(t_env *e, t_room *room)
{
	char	**tab;

	while (room->next)
		room = room->next;
	room->next = crea_room();
	room->next->id = room->id + 1;
	room = room->next;
	tab = ft_strsplit(e->str, ' ');
	room->name = ft_strdup(tab[0]);
	room->x = ft_atoi(tab[1]);
	room->y = ft_atoi(tab[2]);
	if (e->start == 1)
	{
		room->features = 's';
		e->start = 2;
	}
	else if (e->end == 1)
	{
		room->features = 'e';
		e->end = 2;
	}
	else
		room->features = 'n';
}

static void		add_first_room(t_env *e)
{
	char	**tab;

	e->room = crea_room();
	tab = ft_strsplit(e->str, ' ');
	e->room->name = ft_strdup(tab[0]);
	e->room->x = ft_atoi(tab[1]);
	e->room->y = ft_atoi(tab[2]);
	e->room->id = 1;
	if (e->start == 1)
	{
		e->room->features = 's';
		e->start = 2;
	}
	else if (e->end == 1)
	{
		e->room->features = 'e';
		e->end = 2;
	}
	else
		e->room->features = 'n';
}

void			add_room(t_env *e)
{
//	t_room *tmp;

	if (!e->room)
		add_first_room(e);
	else
		add_other_room(e, e->room);
/*	tmp = e->room;
	printf("-------debut liste salle---------\n");
	while (e->room)
	{
		if (e->room->features == 's')
			printf("NAME = %s, X = %d, Y = %d, ID = %d | >>>>>START<<<<<\n", e->room->name, e->room->x, e->room->y, e->room->id);
		else if (e->room->features == 'e')
			printf("NAME = %s, X = %d, Y = %d, ID = %d | >>>>>END<<<<<\n", e->room->name, e->room->x, e->room->y, e->room->id);
		else
		printf("NAME = %s, X = %d, Y = %d, ID = %d\n", e->room->name, e->room->x, e->room->y, e->room->id);
		e->room = e->room->next;
	}
	printf("-------fin liste salle---------\n");
	e->room = tmp;*/
}
