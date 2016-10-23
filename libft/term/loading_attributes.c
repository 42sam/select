/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_attributes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 14:45:04 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/02 23:44:30 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termlib.h"

static void	load_move_attributes(t_attr *g_attr)
{
	g_attr->cm = tgetstr("cm", NULL);
	g_attr->cr = tgetstr("cr", NULL);
	g_attr->up = tgetstr("up", NULL);
	g_attr->down = tgetstr("do", NULL);
	g_attr->left = tgetstr("le", NULL);
	g_attr->right = tgetstr("nd", NULL);
	g_attr->topleft = tgetstr("ho", NULL);
}

static void	load_clearing_attributes(t_attr *g_attr)
{
	g_attr->delchar = tgetstr("dc", NULL);
	g_attr->clear_line = tgetstr("ce", NULL);
	g_attr->clear_up = tgetstr("cl", NULL);
	g_attr->delete_char = tgetstr ("dc", NULL);
	g_attr->clear_till_end_of_screen = tgetstr ("cd", NULL);
}

static void	load_output_attributes(t_attr *g_attr)
{
	g_attr->highlight = tgetstr("mr", NULL);
	g_attr->underlined = tgetstr("us", NULL);
	g_attr->highlightoff = tgetstr("me", NULL);
	g_attr->insert_char = tgetstr ("ic", NULL);
	g_attr->underlined_off = tgetstr("ue", NULL);
	g_attr->blinking_mode = tgetstr ("mb", NULL);
	g_attr->reinit_cursor = tgetstr ("ve", NULL);
	g_attr->invisiblecursor = tgetstr("vi", NULL);
	g_attr->init_sequential_output = tgetstr ("te", NULL);
	g_attr->init_random_cursor_motion = tgetstr ("ti", NULL);
}

t_attr		*load_attributes(t_attr *g_attr)
{
	if ((g_attr = (t_attr *)malloc(sizeof(t_attr))) == NULL)
		return (NULL);
	g_attr->width = tgetnum("co");
	g_attr->height = tgetnum("li");
	g_attr->savecursor = tgetstr ("sc", NULL);
	g_attr->resetcursor = tgetstr ("rc", NULL);
	load_move_attributes(g_attr);
	load_output_attributes(g_attr);
	load_clearing_attributes(g_attr);
	return (g_attr);
}
