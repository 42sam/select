/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 10:44:08 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/16 02:25:29 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termlib.h"

void	switch_to_canonical(void)
{
	tcgetattr(0, &newterm);
	newterm.c_lflag &= ~(ICANON | ECHO);
	newterm.c_cc[VTIME] = 0;
	newterm.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &newterm);
}

void	init_sequential_output(t_attr *g_attr)
{
	tputs(g_attr->init_sequential_output, 1, (void*)ft_put_tty);
}

int		get_term_entry(void)
{
	static char	term_buffer[2048];
	char		*termtype;
	int			success;

	if ((termtype = getenv ("TERM")) == NULL)
	{
		S("select: env error : TERM not set.\n");
		return (-1);
	}
	success = tgetent (term_buffer, termtype);
	if (success < 0)
	{
		S("select: TERM not found.\n");
		return (-1);
	}
	if (success == 0)
	{
		ft_printf("Terminal type `%s' is not defined.\n", termtype);
		return (-1);
	}
	return (0);
}

t_attr	*term_init(void)
{
	t_attr *attr;

	if ((get_term_entry()) == -1)
		return (NULL);
	if ((attr = load_attributes(g_attr)) == NULL)
		return (NULL);
	tcgetattr(0, &oldterm);
	switch_to_canonical();
	return (attr);
}

void	term_reset(t_attr *g_attr)
{
	tcsetattr(0, TCSANOW, &oldterm);
	reinit_cursor(g_attr);
}
