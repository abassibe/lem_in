/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 05:23:53 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/16 05:24:34 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		free_buff(char **buff)
{
	int		i;

	i = -1;
	while (buff[++i])
		free(buff[i]);
	free(buff);
	buff = NULL;
}

void			fill_buff(t_env *e)
{
	char	**tmp;
	int		i;

	if (!e->buff)
	{
		if (!(e->buff = (char **)ft_memalloc(sizeof(char *) * 2)))
			ft_error("ERROR", 1);
		e->buff[0] = ft_strdup(e->str);
	}
	else
	{
		i = 0;
		tmp = e->buff;
		while (tmp[i])
			i++;
		if (!(e->buff = (char **)ft_memalloc(sizeof(char *) * (i + 2))))
			ft_error("ERROR", 1);
		i = -1;
		while (tmp[++i])
			e->buff[i] = ft_strdup(tmp[i]);
		e->buff[i] = ft_strdup(e->str);
		free_buff(tmp);
	}
}
