/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_exist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 05:33:17 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/14 05:34:23 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char			already_exist(const char *str, t_room *room)
{
	char	tmp[100];
	int		i;

	i = 0;
	if (!room || !str)
		return (0);
	while (str[i] && str[i] != ' ')
	{
		tmp[i] = str[i];
		i++;
		if (i >= 100)
			return (1);
	}
	tmp[i] = '\0';
	while (room->next)
	{
		if (!ft_strcmp(tmp, room->name))
			return (1);
		room = room->next;
	}
	return (0);
}

static char		room_exist_2(t_room *room, char **tmp)
{
	int		i;

	i = 0;
	while (room->next)
	{
		if (!ft_strcmp(tmp[0], room->name))
			i++;
		if (!ft_strcmp(tmp[1], room->name))
			i++;
		if (i == 2)
			return (1);
		room = room->next;
	}
	return (0);
}

static void		del_str(char **tmp)
{
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
}

static char		name_too_long(const char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '-')
		i++;
	if (i >= 100)
		return (0);
	while (str[++i])
		j++;
	if (j >= 100)
		return (0);
	return (1);
}

char			room_exist(t_room *room, const char *str)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!room || !str)
		return (0);
	if (!name_too_long(str))
		return (0);
	tmp = ft_strsplit(str, '-');
	if (room_exist_2(room, tmp))
	{
		del_str(tmp);
		return (1);
	}
	del_str(tmp);
	return (0);
}
