/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 05:19:51 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/14 06:02:36 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
/*
char	already_save(t_pipe *pipe, char *str)
{
	if (!pipe)
		return (0);
	while (pipe->next)
	{
		if (!ft_strcmp(str, ))
	}
}

void	add_first(t_room *room, t_pipe *pipe, char str)
{
	if (already_save(pipe, str))
		return ;
	while (room->next)
	{
		if (!ft_strcmp(room->name, str))
		{
			if (!room->pipe)
				room->pipe = crea_pipe();
			else

		}
	}
}

void	add_pipe(t_env *e)
{
	char	**tmp;

	tmp = ft_strsplit(e->str, '-');
	add_first(e->room, e->room->pipe, tmp[0]);
}
*/
char		parsing(t_env *e)
{
	char	c;

	c = which_kind_of_line(e);
	if (c == 'c' && e->args == 2)
	{
//		add_pipe(e);
		ft_printf("Pipe {green}OK{eoc} = %s\n", e->str);
	}
	else if (c == 'b' && e->args == 1)
	{
		add_room(e);
		ft_printf("Room {green}OK{eoc} = %s\n", e->str);
	}
	else if (c == 'a' && e->args == 0)
	{
		e->ants = ft_atoi(e->str);
		e->args = 1;
		ft_printf("Ants {green}OK{eoc} = %d\n", e->ants);
	}
	else if (c == 'e')
	{
		ft_printf("Couille dans l'potage {red}KO{eoc} = %s\n", e->str);
		return (0);
	}
	return (1);
}
