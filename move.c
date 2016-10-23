/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 17:45:13 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/16 02:28:55 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void	go_down(t_args **g_arg, t_args **g_firstarg)
{
	if ((*g_arg)->next)
	{
		(*g_arg)->underlined = 0;
		*g_arg = (*g_arg)->next;
		(*g_arg)->underlined = 1;
	}
	else
	{
		(*g_arg)->underlined = 0;
		*g_arg = *g_firstarg;
		(*g_arg)->underlined = 1;
	}
}

static void	go_up(t_args **g_arg)
{
	(*g_arg)->underlined = 0;
	*g_arg = (*g_arg)->previous;
	(*g_arg)->underlined = 1;
}

int			move(char cmd[], t_args **g_arg, t_args **g_firstarg)
{
	if (ISUP(cmd))
		go_up(g_arg);
	else if (ISDOWN(cmd))
		go_down(g_arg, g_firstarg);
	return (0);
}
