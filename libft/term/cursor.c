/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 14:47:14 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/02 23:44:30 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termlib.h"

void	turn_cursor_invisible(t_attr *g_attr)
{
	tputs(g_attr->invisiblecursor, 1, (void*)ft_put_tty);
}

void	reinit_cursor(t_attr *g_attr)
{
	tputs(g_attr->reinit_cursor, 1, (void*)ft_put_tty);
}
