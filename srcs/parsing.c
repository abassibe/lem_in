/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 05:19:51 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/15 04:58:47 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char		parsing(t_env *e)
{
	char	c;

	c = which_kind_of_line(e);
	if (c == 'c' && e->args == 2)
	{
		add_pipe(e->room, e->str);
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
		if (e->ants <= 0)
			ft_error("Error", 0);
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
