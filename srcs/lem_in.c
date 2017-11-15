/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 00:35:54 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/15 03:30:05 by abassibe         ###   ########.fr       */
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
	pipe->next = NULL;
	pipe->id = 0;
	return (pipe);
}

t_room	*crea_room(void)
{
	t_room	*room;

	if (!(room = (t_room *)ft_memalloc(sizeof(t_room))))
		ft_error("ERROR", 1);
	room->next = NULL;
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
				ft_printf("{green}%d, ", e->room->pipe->id);
			else
				ft_printf("{green}%d{eoc} |\n", e->room->pipe->id);
			e->room->pipe = e->room->pipe->next;
		}
		printf("\n----------------------------\n");
		e->room = e->room->next;
	}
}

int		main(void)
{
	t_env	e;

	e.ants = 0;
	e.args = 0;
	e.room = NULL;
	while (get_next_line(0, &e.str))
		if (parsing(&e) == 0)
			ft_error("ERROR", 0);
	all_print(&e);
	return (0);
}
