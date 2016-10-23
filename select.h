/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 00:14:29 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/17 18:46:22 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H
# include "libft/libft.h"
# include <time.h>
# include <dirent.h>
# define DONE 1
# define ABANDON -1
# define NOTDONE 0

typedef	struct		s_args
{
	char			*name;
	int				selected;
	int				underlined;
	int				display_subfolders;
	struct s_args	*next;
	struct s_args	*previous;
}					t_args;

typedef	struct		s_coordinates
{
	int				x;
	int				y;
	int				maxlen;
}					t_coordinates;

t_args				*g_arg;
t_args				*g_firstarg;

char				*attribute_color_to_type(char *path);
char				*lst_to_str(t_args *node, char c);
char				*read_term(char *buf);
int					end_of_loop_command(char *cmd, t_attr *g_attr);
int					lstlen(t_args *lst);
int					move(char cmd[], t_args **g_arg, t_args **g_firstarg);
int					print_content(t_args *head, t_coordinates *wh);
int					print_one_sub(t_attr *g_attr, char *file, int x, int y);
int					put_screen(t_args *head, t_attr *g_attr);
int					remove_node(t_args *to_delete, t_args **head);
int					search(char cmd[], t_args **g_arg, t_args *g_firstarg,
															t_attr *g_attr);
int					uselect(char cmd[], t_args **g_arg, t_args **g_firstarg,
															t_attr *g_attr);
int					print_one_argument(t_args *g_arg, t_attr *g_attr, int x,
																	int y);
void				del_arg(t_args **g_arg, t_args **g_firstarg, int *stop);
void				deselect_all(t_args *lst);
void				deunderline_all(t_args *lst);
void				launch_screen(t_args *g_arg, t_attr *g_attr);
void				print_footer(t_attr *g_attr);
void				push_arg(t_args **head, t_args *new);
void				put_underlined_or_not(t_args *g_arg, t_attr *g_attr);
void				reinit_xy(t_coordinates *wh);
void				sel_arg(t_args **g_arg, t_args **g_firstarg);
void				select_all(t_args *lst);
void				ununderline_all(t_args *lst);
void				update_maxlen(t_coordinates *wh, char *argument);
t_args				*get_last_node(t_args *node);
t_args				*array_to_dblst(char **args);
t_args				*change_focus_line(t_args *g_firstarg, char to_find[]);
t_args				*new_arg(char *name, t_args *previous);
t_coordinates		*init_coordinates();
int					loop(t_attr *g_attr, t_args *g_arg);
#endif
