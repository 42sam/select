/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 22:39:07 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/16 02:37:28 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void	sigwinsz(int signum)
{
	(void)signum;
	window_management(g_attr);
	put_screen(g_arg, g_attr);
}

void		sigtstp_handler(int signum)
{
	char			*tmp;
	struct termios	tmpattr;

	(void)signum;
	tmp = (char *)malloc(3);
	tcsetattr(0, TCSANOW, &oldterm);
	tcgetattr(0, &tmpattr);
	tmp[0] = tmpattr.c_cc[VSUSP];
	tmp[1] = '\0';
	init_sequential_output(g_attr);
	reinit_cursor(g_attr);
	signal(SIGTSTP, SIG_DFL);
	ioctl(1, TIOCSTI, tmp);
}

void		sigcont_handler(int signum)
{
	(void)signum;
	switch_to_canonical();
	signal(SIGTSTP, sigtstp_handler);
	init_random_cursor_motion(g_attr);
	turn_cursor_invisible(g_attr);
	put_screen(g_firstarg, g_attr);
}

void		signal_handler(int signum)
{
	(void)signum;
	term_reset(g_attr);
	init_sequential_output(g_attr);
	exit(1);
}

void		init_signals(void)
{
	signal(SIGTSTP, sigtstp_handler);
	signal(SIGCONT, sigcont_handler);
	signal(SIGWINCH, sigwinsz);
	signal(SIGHUP, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGILL, signal_handler);
	signal(SIGTRAP, signal_handler);
	signal(SIGABRT, signal_handler);
	signal(SIGEMT, signal_handler);
	signal(SIGFPE, signal_handler);
	signal(SIGBUS, signal_handler);
	signal(SIGSEGV, signal_handler);
	signal(SIGSYS, signal_handler);
	signal(SIGPIPE, signal_handler);
	signal(SIGALRM, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGURG, signal_handler);
	signal(SIGCHLD, signal_handler);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	signal(SIGPROF, signal_handler);
}
