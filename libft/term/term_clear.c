/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/02 23:53:22 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/02 23:58:05 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termlib.h"

void	clear_up(t_attr *g_attr)
{
	tputs(g_attr->clear_up, 1, (void*)ft_put_tty);
}

void	clear_till_end_of_screen(t_attr *g_attr)
{
	tputs(g_attr->clear_till_end_of_screen, 1, (void *)ft_put_tty);
}

void	clear_display(t_attr *g_attr)
{
	top_left(g_attr);
	clear_till_end_of_screen(g_attr);
	top_left(g_attr);
}

void	clearline(t_attr *g_attr)
{
	tputs(g_attr->clear_line, 1, (void*)ft_put_tty);
}

void	insert_char(t_attr *g_attr)
{
	tputs(g_attr->insert_char, 1, (void *)ft_put_tty);
}
