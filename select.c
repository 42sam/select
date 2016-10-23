/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 16:35:07 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/16 02:35:25 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

int		loop(t_attr *g_attr, t_args *g_arg)
{
	t_args	*lastarg;
	int		choice;
	char	cmd[5];

	choice = NOTDONE;
	g_firstarg = g_arg;
	while (choice == NOTDONE)
	{
		lastarg = get_last_node(g_arg);
		g_firstarg->previous = lastarg;
		put_screen(g_firstarg, g_attr);
		read_term(cmd);
		if ((choice = (end_of_loop_command(cmd, g_attr))))
			return (choice);
		if (ISDEL(cmd))
			del_arg(&g_arg, &g_firstarg, &choice);
		move(cmd, &g_arg, &g_firstarg);
		uselect(cmd, &g_arg, &g_firstarg, g_attr);
		search(cmd, &g_arg, g_firstarg, g_attr);
	}
	return (choice);
}

void	return_choice_to_shell(t_args *g_arg)
{
	t_put(attribute_color_to_type(NULL));
	ft_putstr(lst_to_str(g_arg, ' '));
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putstr_fd("ft_select: usage : enter at least one argument\n", 2);
		return (0);
	}
	init_signals();
	if ((g_attr = term_init()) == NULL)
		return (-1);
	g_attr->footer = 4;
	init_random_cursor_motion(g_attr);
	g_arg = array_to_dblst(argv);
	turn_cursor_invisible(g_attr);
	put_screen(g_firstarg, g_attr);
	if ((loop(g_attr, g_arg)) == DONE)
		return_choice_to_shell(g_arg);
	return (0);
}
