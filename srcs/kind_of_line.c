/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kind_of_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 03:33:26 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/13 05:26:23 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	is_ants(t_env *e)
{
	long int	i;

	i = -1;
	while (e->str[++i])
		if (e->str[i] < '0' || e->str[i] > '9')
			return (0);
	if (i > 10)
		return (0);
	i = ft_atoi_long(e->str);
	if (i < -2147483648 || i > 2147483647)
		return (0);
	return (1);
}

int		check_value(char *str)
{
	long int	nb;

	nb = ft_atoi_long(str);
	if (nb < 0 || nb > 2147483647)
		return (0);
	return (1);
}

char	is_room(t_env *e)
{
	int			i;

	i = 0;
	while (e->str[i] != ' ' && e->str[i])
	{
		if (e->str[i] == '-')
			return (0);
		i++;
	}
	if (!e->str[i] || !check_value(&e->str[i]))
		return (0);
	i++;
	while ((e->str[i] >= '0' && e->str[i] <= '9') && e->str[i])
		i++;
	if (!e->str[i] || !check_value(&e->str[i]))
		return (0);
	i++;
	while ((e->str[i] >= '0' && e->str[i] <= '9') && e->str[i])
		i++;
	if (e->str[i])
		return (0);
	return (1);
}

char	is_pipe(t_env *e)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while ((e->str[i] >= '0' && e->str[i] <= '9') && e->str[i])
		i++;
	if (e->str[i] == '-')
		i++;
	else if (i == 0 || e->str[i] != '-')
		return (0);
	while ((e->str[i] >= '0' && e->str[i] <= '9') && e->str[i])
		i++;
	if (e->str[i])
		return (0);
	return ('a');
}

char	is_particular_case(t_env *e)
{
	if (e->str[0] == '#' && e->str[1] == '#')
	{
		if (e->start == 0  && e->str[2] == 's' && e->str[3] == 't' && e->str[4] == 'a' && e->str[5] == 'r' && e->str[6] == 't')
		{
			e->start = 1;
			return (1);
		}
		if (e->end == 0 && e->str[2] == 'e' && e->str[3] == 'n' && e->str[4] == 'd')
		{
			e->end = 1;
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
		return ('d');
	if (is_particular_case(e))
		return ('d');
	else if (is_pipe(e))
		return ('c');
	else if (is_room(e))
		return ('b');
	else if (is_ants(e))
		return ('a');
	return ('e');
}
