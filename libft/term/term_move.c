/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 10:46:44 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/02 23:44:30 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termlib.h"

void	new_line(t_attr *g_attr)
{
	tputs(g_attr->cr, 1, (void*)ft_put_tty);
	tputs(g_attr->down, 1, (void*)ft_put_tty);
}

void	start_of_line(t_attr *g_attr)
{
	tputs(g_attr->cr, 1, (void*)ft_put_tty);
}

void	top_left(t_attr *g_attr)
{
	tputs(g_attr->topleft, 1, (void *)ft_put_tty);
}

void	go_left(t_attr *g_attr)
{
	tputs(g_attr->left, 1, (void*)ft_put_tty);
}

void	go_right(t_attr *g_attr)
{
	tputs(g_attr->right, 1, (void*)ft_put_tty);
}
