/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 05:19:51 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/09 05:51:50 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		parsing(t_env *e)
{
	char	c;

	c = which_kind_of_line(e);
	if (c == 'c')
	{
		if (add_pipes(e) > 0)
			return (1);
	}
	else if (c == 'b')
	{
		if (add_room(e) > 0)
			return (1);
	}
	else if (c == 'a')
	{
		if (pick_nb_ants(e) > 0)
			return (1);
	}
	else
		return (0);
}
