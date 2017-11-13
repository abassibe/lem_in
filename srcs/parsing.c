/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 05:19:51 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/13 05:23:39 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	add_other_room(t_env *e, t_room *room)
{
	char	**tab;

	while (room->next)
		room = room->next;
	room->next = crea_room();
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

void	add_first_room(t_env *e)
{
	char	**tab;

	e->room = crea_room();
	tab = ft_strsplit(e->str, ' ');
	e->room->name = ft_strdup(tab[0]);
	e->room->x = ft_atoi(tab[1]);
	e->room->y = ft_atoi(tab[2]);
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

void	add_room(t_env *e)
{
	t_room *tmp;

	if (!e->room)
		add_first_room(e);
	else
		add_other_room(e, e->room);
	tmp = e->room;
	printf("-------debut liste salle---------\n");
	while (e->room)
	{
		if (e->room->features == 's')
			printf("NAME = %s, X = %d, Y = %d | >>>>>START<<<<<\n", e->room->name, e->room->x, e->room->y);
		if (e->room->features == 'e')
			printf("NAME = %s, X = %d, Y = %d | >>>>>END<<<<<\n", e->room->name, e->room->x, e->room->y);
		else
		printf("NAME = %s, X = %d, Y = %d\n", e->room->name, e->room->x, e->room->y);
		e->room = e->room->next;
	}
	printf("-------fin liste salle---------\n");
	e->room = tmp;
}

int		parsing(t_env *e)
{
	char	c;

	c = which_kind_of_line(e);
	if (c == 'c')
	{
//		if (add_pipes(e) > 0)
			return (1);
	}
	else if (c == 'b')
	{
		add_room(e);
	}
	else if (c == 'a' && e->args == 0)
	{
		e->ants = ft_atoi(e->str);
		e->args = 1;
	}
	else if (c == 'e')
		return (0);
	return (1);
}
