/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kind_of_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 03:33:26 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/27 03:21:25 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static char		is_ants(const char *str)
{
	long int	i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	if (i > 10)
		return (0);
	i = ft_atoi_long(str);
	if (i < -2147483648 || i > 2147483647)
		return (0);
	if (i == 0)
		return (0);
	return (1);
}

static char		is_room(t_room *room, const char *str)
{
	int			i;

	i = 0;
	while (str[i] != ' ' && str[i])
	{
		if (str[i] == '-')
			return (0);
		i++;
	}
	if (!str[i] || !check_value(&str[i]))
		return (0);
	i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
		i++;
	if (!str[i] || !check_value(&str[i]))
		return (0);
	i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
		i++;
	if (str[i])
		return (0);
	if (already_exist(str, room))
		return (0);
	return (1);
}

static char		is_pipe(t_room *room, const char *str)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while ((str[i] != '-' && str[i] != ' ') && str[i])
		i++;
	if (str[i] == '-')
		i++;
	else if (i == 0 || str[i] != '-')
		return (0);
	while ((str[i] != '-' && str[i] != ' ') && str[i])
		i++;
	if (str[i])
		return (0);
	if (!room_exist(room, str))
		return (0);
	return ('a');
}

static char		is_particular_case(char *start, char *end, const char *str)
{
	if (str[0] == '#' && str[1] == '#')
	{
		if (*start == 0  && str[2] == 's' && str[3] == 't' && str[4] == 'a' && str[5] == 'r' && str[6] == 't')
		{
			*start = 1;
			return (1);
		}
		if (*end == 0 && str[2] == 'e' && str[3] == 'n' && str[4] == 'd')
		{
			*end = 1;
			return (1);
		}
		return (1);
	}
	return (0);
}

char	which_kind_of_line(t_env *e)
{
	if (e->str[0] == 'L' || e->str[0] == '-' || e->str[0] == ' ')
		return ('e');
	if (e->str[0] == '#' && e->str[1] != '#')
	{
		return ('d');
	}
	if (is_particular_case(&e->start, &e->end, e->str))
	{
		if (e->start == 1 && e->end == 1)
			return ('e');
		return ('d');
	}
	else if (is_pipe(e->room, e->str))
	{
		e->args = 2;
		return ('c');
	}
	else if (is_room(e->room, e->str))
		return ('b');
	else if (is_ants(e->str))
		return ('a');
	return ('e');
}
