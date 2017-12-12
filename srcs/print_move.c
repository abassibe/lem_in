/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 00:01:27 by abassibe          #+#    #+#             */
/*   Updated: 2017/12/06 01:45:22 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*get_name(int nb, t_room *room)
{
	while (room && room->id != nb)
		room = room->next;
	return (room->name);
}

void	print_move(t_env *e, int to, int ant)
{
	char	*dest;

	dest = get_name(to, e->room);
	ft_printf("L%d-%s ", ant, dest);
}
