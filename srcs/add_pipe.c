/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 02:37:27 by abassibe          #+#    #+#             */
/*   Updated: 2017/12/14 04:36:22 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static char		already_save(t_room *room, const int id, const char *str)
{
	while (room)
	{
		if (!ft_strcmp(room->name, str))
			if (id == room->id)
				return (1);
		room = room->next;
	}
	return (0);
}

static int		add_first(t_room *room, t_room *tmp_room, const char *str)
{
	room->pipe = crea_pipe();
	while (tmp_room && ft_strcmp(str, tmp_room->name))
		tmp_room = tmp_room->next;
	room->pipe->id = tmp_room->id;
	return (room->pipe->id);
}

static int		add_other_pipe(t_pipe *pipe, t_room *room, const char *str)
{
	while (pipe->next)
	{
		if (already_save(room, pipe->id, str))
			return (-1);
		pipe = pipe->next;
	}
	pipe->next = crea_pipe();
	pipe = pipe->next;
	while (room && ft_strcmp(str, room->name))
		room = room->next;
	pipe->id = room->id;
	return (pipe->id);
}

static void		add_connex(t_room *tmp_room, t_pipe *pipe, const t_room *room)
{
	if (!tmp_room->pipe)
	{
		tmp_room->pipe = crea_pipe();
		tmp_room->pipe->id = room->id;
	}
	else
	{
		while (pipe->next)
			pipe = pipe->next;
		pipe->next = crea_pipe();
		pipe->next->id = room->id;
	}
}

void			add_pipe(t_room *room, const char *str)
{
	char	**tmp;
	int		id;
	t_room	*tmp_room;

	tmp_room = room;
	tmp = ft_strsplit(str, '-');
	if (!ft_strcmp(tmp[0], tmp[1]))
		return ;
	while (ft_strcmp(tmp[0], room->name))
		room = room->next;
	if (!room->pipe)
		id = add_first(room, tmp_room, tmp[1]);
	else
		id = add_other_pipe(room->pipe, tmp_room, tmp[1]);
	if (id == -1)
		return ;
	while (tmp_room && tmp_room->id != id)
		tmp_room = tmp_room->next;
	add_connex(tmp_room, tmp_room->pipe, room);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
}
