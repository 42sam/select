/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 10:46:48 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/02 23:44:30 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termlib.h"

void	t_put(char *str)
{
	tputs(str, 1, (void *)ft_put_tty);
}

void	t_put_xy(int x, int y, char *str, t_attr *g_attr)
{
	tputs(tgoto(g_attr->cm, x, y), 1, (void*)ft_put_tty);
	t_put(str);
}

void	ft_put_tty(char c)
{
	int	fd;

	fd = open("/dev/tty", O_WRONLY);
	write(fd, &c, 1);
	close(fd);
}
