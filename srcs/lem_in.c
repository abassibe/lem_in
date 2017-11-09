/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 00:35:54 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/09 01:29:19 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	ft_error(char *str)
{
	perror(str);
	exit(0);
}

t_pipe	*crea_pipe(void)
{
	t_pipe	*pipe;

	if (!(pipe = (t_pipe *)ft_memalloc(sizeof(t_pipe))))
		ft_error("ERROR");
	return (pipe);
}

t_room	*crea_room(void)
{
	t_room	*room;

	if (!(room = (t_room *)ft_memalloc(sizeof(t_room))))
		ft_error("ERROR");
	return (room);
}

int		main(void)
{
	t_env	e;
	char	*buff;

	e.ants = 0;
	while (get_next_line(0, &e.str))
	{
		if (parsing(&e) == 0)
			break ;
	}
	if ((buff = ft_treat(e)) > 0)
		ft_write(buff);
	else
		write(7, "ERROR\n", 2);
	return (0);
}
