/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xy.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 18:03:04 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/16 02:28:55 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void			reinit_xy(t_coordinates *wh)
{
	wh->y = 4;
	wh->x = wh->x + wh->maxlen + 3;
	wh->maxlen = 0;
}

void			update_maxlen(t_coordinates *wh, char *argument)
{
	if (wh->maxlen < (int)ft_strlen(argument))
		wh->maxlen = ft_strlen(argument);
}

t_coordinates	*init_coordinates(void)
{
	t_coordinates	*wh;

	wh = (t_coordinates *)malloc(sizeof(t_coordinates));
	wh->maxlen = 0;
	wh->y = 4;
	wh->x = 0;
	return (wh);
}
