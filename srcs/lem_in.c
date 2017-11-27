/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 00:35:54 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/27 03:27:07 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_error(char *str, char flag)
{
	if (flag == 1)
		perror(str);
	else
	{
		write (2, str, ft_strlen(str));
		write (2, "\n", 1);
	}
	exit(0);
}

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

void	all_print(t_env *e)
{
	ft_printf("ANTS = {green}%d\n", e->ants);
	while (e->room)
	{
		ft_printf("----- Room name = {green}%s{eoc} -----\n", e->room->name);
		ft_printf("| Room ID           = {green}%d{eoc} |\n", e->room->id);
		ft_printf("| Room X            = {green}%d{eoc} |\n", e->room->x);
		ft_printf("| Room Y            = {green}%d{eoc} |\n", e->room->y);
		if (e->room->features == 's')
		ft_printf("| Room features     = {red}START{eoc} |\n");
		else if (e->room->features == 'e')
		ft_printf("| Room features     = {red}END{eoc} |\n");
		else
		ft_printf("| Room features     = {green}NONE{eoc} |\n");
		ft_printf("| Room ID connected = ");
		while (e->room->pipe)
		{
			if (e->room->pipe->next)
				ft_printf("{green}%d{eoc}, ", e->room->pipe->id);
			else
				ft_printf("{green}%d{eoc} |\n", e->room->pipe->id);
			e->room->pipe = e->room->pipe->next;
		}
		printf("\n----------------------------\n");
		e->room = e->room->next;
	}
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
	}
	fill_matrix(&e, e.room);
	enough_data(&e);
	while (e.buff[++i])
	{
		write(1, e.buff[i], ft_strlen(e.buff[i]));
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
	all_print(&e);
	algo(&e);
	return (0);
}
