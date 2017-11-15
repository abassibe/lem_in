/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 02:37:27 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/15 04:51:17 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	already_save(t_room *room, int id, char *str)
{
	while (room->next)
	{
		if (!ft_strcmp(room->name, str))
			if (id == room->id)
				return (1);
		room = room->next;
	}
	return (0);
}

int		add_first(t_room *room, t_room *tmp_room, char *str)
{
	room->pipe = crea_pipe();
	while (tmp_room && ft_strcmp(str, tmp_room->name))
		tmp_room = tmp_room->next;
	room->pipe->id = tmp_room->id;
	return (room->pipe->id);
}

int		add_other_pipe(t_pipe *pipe, t_room *room, char *str)
{
	while (pipe->next)
	{
		if (already_save(room, pipe->id, str))
			return (0);
		pipe = pipe->next;
	}
	pipe->next = crea_pipe();
	pipe = pipe->next;
	while (ft_strcmp(str, room->name))
		room = room->next;
	pipe->id = room->id;
	return (pipe->id);
}

void	add_pipe(t_room *room, char *str)
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
		id = add_other_pipe(room->pipe, room, tmp[1]);
	if (id == 0)
		return ;
	while (tmp_room && tmp_room->id != id)
		tmp_room = tmp_room->next;
	if (!tmp_room->pipe)
		tmp_room->pipe = crea_pipe();
	tmp_room->pipe->id = room->id;
}
