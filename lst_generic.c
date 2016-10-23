/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 17:57:34 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/16 02:28:55 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

t_args			*array_to_dblst(char **args)
{
	t_args	*g_arg;
	t_args	*head;
	t_args	*previous;
	t_args	**headref;
	int		i;

	i = 0;
	head = NULL;
	headref = &head;
	previous = NULL;
	args++;
	while (*args)
	{
		g_arg = new_arg(*args, previous);
		if (i++ == 0)
			g_arg->underlined = 1;
		push_arg(headref, g_arg);
		previous = g_arg;
		headref = &((*headref)->next);
		args++;
	}
	head->previous = g_arg;
	return (head);
}

void			push_arg(t_args **head, t_args *new)
{
	if (head && new)
	{
		new->next = *head;
		*head = new;
	}
}

int				remove_node(t_args *to_delete, t_args **head)
{
	t_args	*before;
	t_args	*node;

	if (ft_strequ((*head)->name, to_delete->name))
	{
		*head = (*head)->next;
		if (*head == NULL)
			return (-1);
	}
	node = *head;
	while (node)
	{
		if (ft_strequ(node->name, to_delete->name))
		{
			before->next = node->next;
			if (node->next)
				(node->next)->previous = before;
		}
		before = node;
		node = node->next;
	}
	return (1);
}

t_args			*new_arg(char *name, t_args *previous)
{
	t_args	*g_arg;

	g_arg = (t_args *)malloc(sizeof(t_args));
	g_arg->name = name;
	g_arg->selected = 0;
	g_arg->previous = previous;
	g_arg->next = NULL;
	return (g_arg);
}

struct s_args	*get_last_node(t_args *node)
{
	while (node->next)
		node = node->next;
	return (node);
}
