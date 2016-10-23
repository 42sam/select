/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 03:47:34 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/16 02:28:55 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

char			*lst_to_str(t_args *node, char c)
{
	char	*str;
	int		i;

	i = 0;
	if (node->selected)
	{
		str = makestr(node->name);
		i++;
	}
	else
		str = makestr("");
	node = node->next;
	while (node)
	{
		if (node->selected)
		{
			if (i != 0)
				str = ft_strjoin(str, char_to_str(c));
			str = ft_strjoin(str, node->name);
			i++;
		}
		node = node->next;
	}
	return (str);
}

int				lstlen(t_args *lst)
{
	int len;

	if (!lst)
		return (-1);
	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
