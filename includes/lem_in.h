/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 00:36:44 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/27 05:15:44 by abassibe         ###   ########.fr       */
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
	char			**buff;
	char			*str;
	char			args;
	char			start;
	char			end;
	int				ind;
	char			**matrix;
	int				nb_room;
	int				*path;
	int				max_path;
	int				start_id;
	int				end_id;
	int				*bl;
	t_room			*room;
}					t_env;

char				parsing(t_env *e);
t_room				*crea_room();
t_pipe				*crea_pipe();
char				check_value(const char *str);
char				which_kind_of_line(t_env *e);
void				add_room(t_env *e);
char				already_exist(const char *str, t_room *room);
char				room_exist(t_room *room, const char *str);
void				add_pipe(t_room *room, const char *str);
void				enough_data(t_env *e);
void				fill_buff(t_env *e);
void				ft_error(char *str, char flag);
void				init_struct(t_env *e);
void				all_print(t_env *e);
void				algo(t_env *e);

#endif
