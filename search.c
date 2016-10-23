/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 17:54:28 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/16 02:28:55 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	print_to_find(t_attr *g_attr, int len_max, char *to_find, char *buf)
{
	ft_strcat(to_find, buf);
	if (len_max < (g_attr->width - 30))
		t_put_xy(10, 1, to_find, g_attr);
	if (len_max == (g_attr->width - 30))
		t_put("...");
}

t_args	*search_command(t_args *g_firstarg)
{
	int		rd;
	char	buf[20000];
	char	to_find[20000];
	int		len_max;

	len_max = 0;
	ft_bzero(buf, 20000);
	ft_bzero(to_find, 20000);
	while (!ISRETURN(buf))
	{
		len_max++;
		rd = read(0, buf, 200);
		buf[rd] = '\0';
		if (!ISRETURN(buf))
		{
			if (ISASCII(buf))
				print_to_find(g_attr, len_max, to_find, buf);
		}
	}
	return (change_focus_line(g_firstarg, to_find));
}

int		search(char cmd[], t_args **g_arg, t_args *g_firstarg, t_attr *g_attr)
{
	t_args	*tmparg;

	tmparg = *g_arg;
	if (ISCTRLF(cmd))
	{
		t_put_xy(0, 1, "Search : ", g_attr);
		if ((tmparg = search_command(g_firstarg)) == NULL)
		{
			start_of_line(g_attr);
			clearline(g_attr);
			t_put_xy(0, 1, "Search : argument not found", g_attr);
			sleep(1);
		}
		else
			*g_arg = tmparg;
	}
	else if (ISTAB(cmd))
	{
		if ((*g_arg)->display_subfolders)
			(*g_arg)->display_subfolders = 0;
		else
			(*g_arg)->display_subfolders = 1;
	}
	return (0);
}
