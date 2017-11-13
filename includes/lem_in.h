/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 00:36:44 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/13 04:50:01 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

typedef struct		s_pipe
{
	struct s_pipe	*next;
	int				id;
}					t_pipe;

typedef struct		s_room
{
	struct s_room	*next;
	char			*name;
	int				id;
	int				x;
	int				y;
	char			features;
	t_pipe			*pipe;
}					t_room;

typedef struct		s_env
{
	int				ants;
	char			*str;
	char			args;
	char			start;
	char			end;
	t_room			*room;
}					t_env;

int				parsing(t_env *e);
t_room			*crea_room();
t_pipe			*crea_pipe();
char			which_kind_of_line(t_env *e);
void			ft_error(char *str);

#endif
