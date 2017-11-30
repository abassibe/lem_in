/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 05:19:51 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/30 04:14:04 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char		parsing(t_env *e)
{
	char	c;

	c = which_kind_of_line(e);
	if (c == 'c' && e->args == 2)
		add_pipe(e->room, e->str);
	else if (c == 'b' && e->args == 1)
		add_room(e);
	else if (c == 'a' && e->args == 0)
	{
		e->ants = ft_atoi(e->str);
		if (e->ants <= 0)
			ft_error("Error", 0);
		e->args = 1;
	}
	else if (c == 'e')
		return (0);
	return (1);
}
