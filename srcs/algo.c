/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:05:48 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/27 05:52:04 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	get_max_path(t_env *e)
{
	int		i;
	int		tmp;

	i = -1;
	tmp = 0;
	while (++i < e->nb_room)
		if (e->matrix[e->start_id][i] == '1')
			e->max_path++;
	i = -1;
	while (++i < e->nb_room)
		if (e->matrix[e->end_id][i] == '1')
			tmp++;
	if (tmp > 0 && e->max_path > tmp)
		e->max_path = tmp;
	if (e->max_path > e->ants)
		e->max_path = e->ants;
}

char		already_check(int ind, int i, int *path, int *bl)
{
	int		j;

	j = -1;
	while (++j != ind)
		if (path[j] == i)
			return (1);
	j = -1;
	while (bl[j] != -1)
	{
		if (bl[j] == i)
			return (1);
		j++;
	}
	return (0);
}

int		*path_finding(t_env *e, char *str, int id)
{
	int		i;

	i = 0;
	if (str[e->end_id] == '1')
	{
		e->path[e->ind] = id;
		return (e->path);
	}
	while (i < e->ind)
		i++;
	e->path[i] = id;
	e->ind++;
	i = -1;
	while (++i < e->nb_room)
		if (str[i] == '1' && !already_check(e->ind, i, e->path, e->bl) &&
		path_finding(e, e->matrix[i], i))
			return (e->path);
	i = 0;
	while (i != e->ind)
		i++;
	e->path[i] = -1;
	e->ind--;
	return (NULL);
}

void	fill_bl(t_env *e)
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

int		**set_paths(int max_path, int nb_room)
{
	int		**paths;
	int		i;

	i = -1;
	if (!(paths = (int **)ft_memalloc((sizeof(int *) * max_path) + 1)))
		ft_error("ERROR", 1);
	while (++i < max_path)
		if (!(paths[i] = (int *)ft_memalloc((sizeof(int) * nb_room) + 1)))
			ft_error("ERROR", 1);
	return (paths);
}

void	get_path(t_env *e)
{
	int		i;
	int		j = 0;
	int		**paths;

	i = -1;
	paths = set_paths(e->max_path, e->nb_room);
	while (++i < e->max_path)
	{
		e->path = paths[i];
	printf("e->path = %p\n", e->path);
	printf("  paths = %p\n", paths);
		if (!(paths[i] = path_finding(e, e->matrix[e->start_id], e->start_id)))
			break ;
		fill_bl(e);
	printf("e->path = %p\n", e->path);
	printf("   path = %p\n", paths);
		printf("path =");
		while (paths[i][j])
		{
			printf(" %d", paths[i][j]);
			j++;
		}
		printf("\n");
	}
}

void	algo(t_env *e)
{
	int		i;

	i = -1;
	free(e->path);
	if (!(e->bl = (int *)ft_memalloc((sizeof(int) * e->nb_room))))
		ft_error("ERROR", 1);
	while (++i < e->nb_room)
		e->bl[i] = -1;
	get_max_path(e);
	e->ind = 0;
	get_path(e);
}
