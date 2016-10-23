/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 17:55:41 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/16 02:28:55 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

char			*attribute_color_to_type(char *path)
{
	struct stat		details;
	char			*color;

	if (path == NULL)
		return (makestr("\033[39m"));
	lstat(path, &details);
	if ((details.st_mode & S_IFMT) == S_IFDIR)
	{
		color = makestr("\033[91m");
		if (!(details.st_mode & S_IRUSR))
			color = makestr("\033[30m");
	}
	else if ((details.st_mode & S_IFMT) == S_IFREG)
	{
		color = makestr("\033[33m");
		if (!(details.st_mode & S_IRUSR))
			color = makestr("\033[30m");
	}
	else
		color = makestr("\033[34m");
	return (color);
}

void			put_underlined_or_not(t_args *g_arg, t_attr *g_attr)
{
	if (!g_arg->underlined && !g_arg->selected)
	{
		t_put(attribute_color_to_type(g_arg->name));
		t_put(g_arg->name);
		t_put(attribute_color_to_type(NULL));
	}
	else if (g_arg->underlined && g_arg->selected)
	{
		t_put(attribute_color_to_type(g_arg->name));
		put_underlined_highlighted(g_arg->name, g_attr);
		t_put(attribute_color_to_type(NULL));
	}
	else if (!g_arg->underlined && g_arg->selected)
	{
		t_put(attribute_color_to_type(g_arg->name));
		put_highlighted(g_arg->name, g_attr);
		t_put(attribute_color_to_type(NULL));
	}
	else if (g_arg->underlined && !g_arg->selected)
	{
		t_put(attribute_color_to_type(g_arg->name));
		put_underlined(g_arg->name, g_attr);
		t_put(attribute_color_to_type(NULL));
	}
}
