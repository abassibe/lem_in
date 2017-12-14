/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 05:19:51 by abassibe          #+#    #+#             */
/*   Updated: 2017/12/13 04:50:34 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char		parsing(t_env *e)
{
	char	c;

	c = which_kind_of_line(e);
	if (c == 'd')
		return (1);
	if (c == 'c' && e->args == 2)
	{
		add_pipe(e->room, e->str);
		return (1);
	}
	else if (c == 'b' && e->args == 1)
	{
		add_room(e);
		return (1);
	}
	else if (c == 'a' && e->args == 0)
	{
		e->ants = ft_atoi(e->str);
		if (e->ants <= 0)
			ft_error("ERROR", 0);
		e->args = 1;
		return (1);
	}
	return (0);
}
