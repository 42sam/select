/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_assistant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 10:43:10 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/14 16:06:56 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termlib.h"

char	*read_term(char *buf)
{
	int		rd;

	ft_bzero(buf, 10);
	rd = read(0, buf, 12);
	buf[rd] = '\0';
	return (buf);
}

void	window_management(t_attr *g_attr)
{
	struct winsize wsize;

	ioctl(0, TIOCGWINSZ, &wsize);
	g_attr->width = wsize.ws_col;
	g_attr->height = wsize.ws_row;
	g_attr->footer = ((g_attr->width < 60) && (g_attr->height < 25) ? 0 : 4);
}

void	init_random_cursor_motion(t_attr *g_attr)
{
	tputs(g_attr->init_random_cursor_motion, 1, (void*)ft_put_tty);
}
