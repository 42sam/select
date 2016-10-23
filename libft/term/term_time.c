/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 10:42:39 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/16 02:25:14 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termlib.h"

void	child_signalhandler(int signum)
{
	(void)signum;
	exit(1);
}

void	display_time(t_attr *g_attr)
{
	char			*time_displayed;
	time_t			t;
	struct tm		*ltime;
	struct winsize	wsize;

	ioctl(0, TIOCGWINSZ, &wsize);
	g_attr->width = wsize.ws_col;
	g_attr->height = wsize.ws_row;
	if (g_attr->width > 12)
	{
		time(&t);
		ltime = localtime(&t);
		JOIN(&time_displayed, "[%02d:%02d:%02d]",
				ltime->tm_hour, ltime->tm_min, ltime->tm_sec);
		t_put_xy(g_attr->width - 11, 1, time_displayed, g_attr);
	}
}

void	display_time_loop(t_attr *g_attr)
{
	sleep(1);
	while (42)
	{
		display_time(g_attr);
		sleep(1);
	}
}

int		clock_fork(int *g_pid, t_attr *g_attr)
{
	clear_display(g_attr);
	if ((*g_pid = fork()) == 0)
		display_time_loop(g_attr);
	return (*g_pid);
}
