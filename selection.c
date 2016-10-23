/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 17:41:35 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/16 02:28:55 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		uselect(char cmd[], t_args **g_arg, t_args **g_firstarg, t_attr *g_attr)
{
	if (ISSPACE(cmd))
		sel_arg(g_arg, g_firstarg);
	if (ISPAGEUP(cmd))
	{
		select_all(*g_firstarg);
		clear_display(g_attr);
	}
	if (ISPAGEDOWN(cmd))
	{
		deselect_all(*g_firstarg);
		deunderline_all(*g_firstarg);
		(*g_arg)->underlined = 1;
		clear_display(g_attr);
	}
	return (0);
}

void	select_all(t_args *lst)
{
	while (lst)
	{
		lst->selected = 1;
		lst = lst->next;
	}
}

void	deselect_all(t_args *lst)
{
	while (lst)
	{
		lst->selected = 0;
		lst = lst->next;
	}
}

void	sel_arg(t_args **g_arg, t_args **g_firstarg)
{
	if (!(*g_arg)->selected)
	{
		(*g_arg)->selected = 1;
		(*g_arg)->underlined = 0;
		if ((*g_arg)->next)
		{
			*g_arg = (*g_arg)->next;
			(*g_arg)->underlined = 1;
		}
		else
		{
			*g_arg = *g_firstarg;
			(*g_arg)->underlined = 1;
		}
	}
	else
		(*g_arg)->selected = 0;
}

t_args	*change_focus_line(t_args *g_firstarg, char to_find[])
{
	t_args	*node;

	node = g_firstarg;
	while (node)
	{
		if (ft_strstr(node->name, to_find))
		{
			ununderline_all(g_firstarg);
			node->underlined = 1;
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}
