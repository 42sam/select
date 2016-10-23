/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 17:47:17 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/17 17:43:43 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void			print_footer(t_attr *g_attr)
{
	if ((g_attr->width > 60) && (g_attr->height > 25))
	{
		tputs(tgoto(g_attr->cm, 0, g_attr->height - g_attr->footer), 1,
				(void*)ft_put_tty);
		highlight(g_attr);
		t_put(" [Menu] :                      [ESC]       = quit            ");
		new_line(g_attr);
		t_put(" [space]     = select          [delete]   = delete           ");
		new_line(g_attr);
		t_put(" [page up]   = select all      [CTRL + O] = Directory content");
		new_line(g_attr);
		t_put(" [page down] = deselect all    [CTRL + F] = Search           ");
		t_put("");
		new_line(g_attr);
		highlightoff(g_attr);
	}
}

int				print_one_sub(t_attr *g_attr, char *file, int x, int y)
{
	int		arglen;

	arglen = (int)ft_strlen(file);
	if ((arglen + x) > (g_attr->width))
	{
		t_put(makestr("..."));
		return (-1);
	}
	else
		t_put_xy(x, y, file, g_attr);
	return (0);
}

int				print_content(t_args *head, t_coordinates *wh)
{
	DIR				*dir;
	struct dirent	*dp;

	if (is_directory(head->name) && head->display_subfolders)
	{
		if ((dir = opendir(head->name)) != NULL)
		{
			while ((dp = readdir(dir)) != NULL)
			{
				if (!ft_strequ(dp->d_name, "..") && !ft_strequ(dp->d_name, "."))
				{
					update_maxlen(wh, dp->d_name);
					if (print_one_sub(g_attr, dp->d_name, wh->x, wh->y))
						return (-1);
					else
						wh->y++;
					if (wh->y >= (g_attr->height - g_attr->footer))
						reinit_xy(wh);
				}
			}
			closedir(dir);
		}
	}
	return (0);
}

int				print_one_argument(t_args *g_arg, t_attr *g_attr, int x, int y)
{
	int		arglen;
	int		restspace;

	tputs(tgoto(g_attr->cm, x, y), 1, (void*)ft_put_tty);
	arglen = (int)ft_strlen(g_arg->name);
	if ((arglen + x) > g_attr->width)
	{
		restspace = g_attr->width - x - 1;
		if (restspace >= 3)
			t_put(makestr("..."));
		else
			t_put_xy(g_attr->width - 3, g_attr->height - 1, makestr("..."),
					g_attr);
		return (-1);
	}
	put_underlined_or_not(g_arg, g_attr);
	tputs(tgoto(g_attr->cm, x, y), 1, (void*)ft_put_tty);
	start_of_line(g_attr);
	return (0);
}

int				put_screen(t_args *head, t_attr *g_attr)
{
	t_coordinates	*wh;

	g_attr->footer = ((g_attr->width > 60) && (g_attr->height > 25)) ? 4 : 0;
	wh = init_coordinates();
	clear_display(g_attr);
	while (head)
	{
		update_maxlen(wh, head->name);
		if (print_one_argument(head, g_attr, wh->x, wh->y))
			break ;
		else
			wh->y++;
		if (wh->y >= (g_attr->height - g_attr->footer))
			reinit_xy(wh);
		if (print_content(head, wh))
			break ;
		if (wh->y >= (g_attr->height - g_attr->footer))
			reinit_xy(wh);
		head = head->next;
	}
	print_footer(g_attr);
	display_time(g_attr);
	return (0);
}
