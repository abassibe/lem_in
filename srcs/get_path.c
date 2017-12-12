/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 00:16:52 by abassibe          #+#    #+#             */
/*   Updated: 2017/12/01 02:17:33 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static char		already_check(const int ind, const int i, int *path, int *bl)
{
	int		j;

	j = -1;
	while (++j != ind)
		if (path[j] == i)
			return (1);
	j = 0;
	while (bl[j] != -1)
	{
		if (bl[j] == i)
			return (1);
		j++;
	}
	return (0);
}

static int		*path_finding(t_env *e, char *str, const int id)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (str[e->end_id] == '1')
	{
		e->path[e->ind] = id;
		return (e->path);
	}
	e->path[e->ind] = id;
	e->ind++;
	while (++i < e->nb_room)
		if (str[i] == '1' && !already_check(e->ind, i, e->path, e->bl) &&
		path_finding(e, e->matrix[i], i))
			return (e->path);
	i = 0;
	while (i != e->ind)
		i++;
	while (e->bl[j] != -1)
		j++;
	e->bl[j] = e->path[i];
	e->path[i] = -1;
	e->ind--;
	return (NULL);
}

static void		fill_bl(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (e->bl[i] != -1)
		i++;
	while (e->path[j] != -1)
		e->bl[i++] = e->path[j++];
}

static int		**set_paths(const int max_path, const int nb_room)
{
	int		**paths;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!(paths = (int **)ft_memalloc((sizeof(int *) * max_path))))
		ft_error("ERROR", 1);
	while (++i < max_path)
		if (!(paths[i] = (int *)ft_memalloc((sizeof(int) * nb_room))))
			ft_error("ERROR", 1);
	i = -1;
	while (++i < max_path)
	{
		while (++j < nb_room)
			paths[i][j] = -1;
		j = -1;
	}
	return (paths);
}

int				**get_path(t_env *e)
{
	int		i;
	int		**paths;

	i = -1;
	free(e->path);
	paths = set_paths(e->max_path, e->nb_room);
	while (++i < e->max_path)
	{
		e->path = paths[i];
		if (!(path_finding(e, e->matrix[e->start_id], e->start_id)))
			break ;
		fill_bl(e);
		e->nb_paths++;
		e->ind = 0;
	}
	return (paths);
}
