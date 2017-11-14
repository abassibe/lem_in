/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 00:35:54 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/14 03:22:30 by abassibe         ###   ########.fr       */
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

int		main(void)
{
	t_env	e;

	e.ants = 0;
	e.args = 0;
	e.room = NULL;
	while (get_next_line(0, &e.str))
		if (parsing(&e) == 0)
			ft_error("ERROR", 0);
	return (0);
}
