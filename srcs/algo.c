/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:05:48 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/28 05:58:37 by abassibe         ###   ########.fr       */
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
	int		j;

	i = -1;
	j = -1;
	if (!(paths = (int **)ft_memalloc((sizeof(int *) * max_path) + 1)))
		ft_error("ERROR", 1);
	while (++i < max_path + 1)
		if (!(paths[i] = (int *)ft_memalloc((sizeof(int) * nb_room) + 1)))
			ft_error("ERROR", 1);
	i = -1;
	while (++i < max_path + 1)
	{
		while (++j < nb_room + 1)
			paths[i][j] = -1;
		j = -1;
	}
	return (paths);
}

int		**get_path(t_env *e)
{
	int		i;
//	int		j = 0;
	int		**paths;

	i = -1;
	paths = set_paths(e->max_path, e->nb_room);
	while (++i < e->max_path)
	{
		e->path = paths[i];
		if (!(path_finding(e, e->matrix[e->start_id], e->start_id)))
			break ;
		fill_bl(e);
		e->nb_paths++;
/*		printf("path =");
		while (paths[i][j] != -1)
		{
			printf(" %d", paths[i][j]);
			j++;
		}
		j = 0;
		printf("\n");*/
		e->ind = 0;
	}
	return (paths);
}

int		limit_ants(int **paths, int nb_paths)
{
	int		nb;
	int		i;
	int		j;

	i = -1;
	j = -1;
	nb = 0;
	while (++i < nb_paths - 1)
	{
		while (paths[i][++j] != -1)
			nb++;
		j = -1;
	}
	return (nb);
}

int		get_index(int *path)
{
	int		i;

	i = 0;
	while (path[i] != -1)
		i++;
	return (i);
}

void	send_ants(t_env *e, int **paths)
{
	int		i;
	int		j;

	i = -1;
	while (e->ants > 0)
	{
		if (e->nb_paths > 1 && (e->ants - 1) - limit_ants(paths, e->nb_paths) < 1)
			e->nb_paths--;
		while (++i < e->nb_paths)
		{
			j = get_index(paths[i]);
			while (j >= 0)
			{
				if (e->matrix[0][paths[i][j]])
				{
					e->matrix[0][paths[i][j]] = 0;
					if (paths[i][j + 1] == -1)
					{
						printf("L%d-%d ", paths[i][j], e->end_id);
					}
					else
					{
						printf("L%d-%d ", paths[i][j], paths[i][j + 1]);
						e->matrix[0][paths[i][j + 1]] = 1;
					}
				}
				j--;
			}
			j = 0;
			e->matrix[0][paths[i][j + 1]] = 1;
			printf("L%d-%d ", paths[i][j], paths[i][j + 1]);
		}
		printf("\n");
		e->ants -= e->nb_paths;
		i = -1;
	}
}

void	reset_matrix(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < e->nb_room)
	{
		while (++j < e->nb_room)
			e->matrix[i][j] = 0;
		j = -1;
	}
}

void	algo(t_env *e)
{
	int		i;
	int		**paths;

	i = -1;
	free(e->path);
	if (!(e->bl = (int *)ft_memalloc((sizeof(int) * e->nb_room))))
		ft_error("ERROR", 1);
	while (++i < e->nb_room)
		e->bl[i] = -1;
	get_max_path(e);
	e->ind = 0;
	paths = get_path(e);
	reset_matrix(e);
	send_ants(e, paths);
}
