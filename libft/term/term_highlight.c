/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_highlight.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 09:57:44 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/02 23:44:30 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termlib.h"

void	highlight(t_attr *g_attr)
{
	tputs(g_attr->highlight, 1, (void *)ft_put_tty);
}

void	highlightoff(t_attr *g_attr)
{
	tputs(g_attr->highlightoff, 1, (void *)ft_put_tty);
}

void	put_highlighted(char *str, t_attr *g_attr)
{
	highlight(g_attr);
	t_put(str);
	highlightoff(g_attr);
}
