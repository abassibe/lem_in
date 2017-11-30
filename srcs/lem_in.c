/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 00:35:54 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/30 06:00:21 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_pipe	*crea_pipe(void)
{
	t_pipe	*pipe;

	if (!(pipe = (t_pipe *)ft_memalloc(sizeof(t_pipe))))
		ft_error("ERROR", 1);
	return (pipe);
}

t_room	*crea_room(void)
{
	t_room	*room;

	if (!(room = (t_room *)ft_memalloc(sizeof(t_room))))
		ft_error("ERROR", 1);
	return (room);
}

void	get_pipe_id(t_pipe *pipe, char *str, int nb_room)
{
	int		i;

	i = -1;
	while (++i < nb_room)
		str[i] = '0';
	while (pipe)
	{
		str[pipe->id] = '1';
		pipe = pipe->next;
	}
}

void	fill_matrix(t_env *e, t_room *room)
{
	int		i;

	i = -1;
	if (!(e->matrix = (char **)ft_memalloc(sizeof(char *) * e->nb_room)))
		ft_error("ERROR", 1);
	while (++i < e->nb_room)
		e->matrix[i] = ft_strnew(e->nb_room + 1);
	while (room)
	{
		get_pipe_id(room->pipe, e->matrix[room->id], e->nb_room);
		room = room->next;
	}
}

int		main(void)
{
	t_env	e;
	int		i;

	i = -1;
	init_struct(&e);
	while (get_next_line(0, &e.str))
	{
		if (parsing(&e) == 0)
			break ;
		fill_buff(&e);
		free(e.str);
	}
	fill_matrix(&e, e.room);
	enough_data(&e);
	while (e.buff[++i])
	{
		write(1, e.buff[i], ft_strlen(e.buff[i]));
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
	algo(&e);
	while (1)
		;
	return (0);
}
