/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   underlining.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 17:49:47 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/16 02:28:55 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

void			ununderline_all(t_args *lst)
{
	while (lst)
	{
		lst->underlined = 0;
		lst = lst->next;
	}
}

void			deunderline_all(t_args *lst)
{
	while (lst)
	{
		lst->underlined = 0;
		lst = lst->next;
	}
}
