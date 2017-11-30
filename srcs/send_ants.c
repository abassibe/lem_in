/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 00:50:24 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/30 02:07:44 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		get_index(const int *path)
{
	int		i;

	i = 0;
	while (path[i] != -1)
		i++;
	return (i - 1);
}

static int		limit_ants(int **paths, const int nb_paths)
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

static void		send_ants2(t_env *e, int **paths, int *i, int *end)
{
	int		j;

	j = get_index(paths[(*i)]) + 1;
	while (--j >= 0)
	{
		if (e->matrix[0][paths[(*i)][j]])
		{
			e->matrix[0][paths[(*i)][j]] = 0;
			if (paths[(*i)][j + 1] == -1)
			{
				print_move(e, paths[(*i)][j], e->end_id);
				(*end)++;
			}
			else
			{
				print_move(e, paths[(*i)][j], paths[(*i)][j + 1]);
				e->matrix[0][paths[(*i)][j + 1]] = 1;
			}
		}
	}
	if (e->ants > 0)
	{
		e->matrix[0][paths[(*i)][1]] = 1;
		print_move(e, paths[(*i)][0], paths[(*i)][1]);
	}
}

static void		send_ants3(t_env *e, int **paths, int *i, int *end)
{
	int		j;

	j = get_index(paths[(*i)]);
	while (j >= 0)
	{
		if (e->matrix[0][paths[(*i)][j]])
		{
			e->matrix[0][paths[(*i)][j]] = 0;
			if (paths[(*i)][j + 1] == -1)
			{
				print_move(e, paths[(*i)][j], e->end_id);
				(*end)++;
			}
			else
			{
				print_move(e, paths[(*i)][j], paths[(*i)][j + 1]);
				e->matrix[0][paths[(*i)][j + 1]] = 1;
			}
		}
		j--;
	}
	(*i)++;
}

void			send_ants(t_env *e, int **paths, int ant_max)
{
	int		i;
	int		j;
	int		end;

	i = -1;
	end = 0;
	j = 0;
	while (end < ant_max)
	{
		if (e->nb_paths > 1 &&
				(e->ants - 1) - limit_ants(paths, e->nb_paths) < 1)
			e->nb_paths--;
		while (++i < e->nb_paths)
			send_ants2(e, paths, &i, &end);
		while (i < e->max_path)
			send_ants3(e, paths, &i, &end);
		write(1, "\n", 1);
		e->ants -= e->nb_paths;
		i = -1;
	}
}
