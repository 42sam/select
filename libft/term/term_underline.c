/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_underline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 09:56:49 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/02 23:44:30 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termlib.h"

void	underlined(t_attr *g_attr)
{
	tputs(g_attr->underlined, 1, (void *)ft_put_tty);
}

void	underlined_off(t_attr *g_attr)
{
	tputs(g_attr->underlined_off, 1, (void *)ft_put_tty);
}

void	put_underlined(char *str, t_attr *g_attr)
{
	underlined(g_attr);
	t_put(str);
	underlined_off(g_attr);
}

void	put_underlined_highlighted(char *str, t_attr *g_attr)
{
	highlight(g_attr);
	underlined(g_attr);
	t_put(str);
	underlined_off(g_attr);
	highlightoff(g_attr);
}
