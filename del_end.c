/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 18:05:15 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/16 02:31:06 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void	del_arg(t_args **g_arg, t_args **g_firstarg, int *stop)
{
	if (remove_node(*g_arg, g_firstarg) == -1)
	{
		*stop = 1;
		term_reset(g_attr);
		init_sequential_output(g_attr);
	}
	else
	{
		if ((*g_arg)->next)
			*g_arg = (*g_arg)->next;
		else
			*g_arg = (*g_arg)->previous;
		(*g_arg)->underlined = 1;
	}
}

int		end_of_loop_command(char *cmd, t_attr *g_attr)
{
	int		choice;

	choice = NOTDONE;
	if (ISESC(cmd))
	{
		choice = ABANDON;
		term_reset(g_attr);
		init_sequential_output(g_attr);
	}
	else if (ISRETURN(cmd))
	{
		choice = DONE;
		term_reset(g_attr);
		init_sequential_output(g_attr);
	}
	return (choice);
}
