/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 12:00:38 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/16 02:32:21 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMLIB_H
# define TERMLIB_H

# include "../libft.h"
# include <termios.h>
# include <term.h>
# include <signal.h>
# include <sys/ioctl.h>

# define ISUP(B) (((B[0] == 27) && (B[1] == 91) && (B[2] == 65)) ? 1 : 0)
# define ISDOWN(B) (((B[0] == 27) && (B[1] == 91) && (B[2] == 66)) ? 1 : 0)
# define ISPAGEUP(B) (((B[0] == 27) && (B[1] == 91) && (B[2] == 53)) ? 1 : 0)
# define ISPAGEDOWN(B) (((B[0] == 27) && (B[1] == 91) && (B[2] == 54)) ? 1 : 0)
# define ISLEFT(B) (((B[0] == 27) && (B[1] == 91) && (B[2] == 68)) ? 1 : 0)
# define ISRIGHT(B) (((B[0] == 27) && (B[1] == 91) && (B[2] == 67)) ? 1 : 0)
# define ISEND(B) (((B[0] == 27) && (B[1] == 91) && (B[2] == 70)))
# define ISHOME(B) (((B[0] == 27) && (B[1] == 91) && (B[2] == 72)))
# define ISASCII(B) ((ft_isascii(B[0]) && (B[1] == 0)))
# define ISESC(B) (((B[0] == 27) && (B[1] == 0)) ? 1 : 0)
# define ISTAB(B) ((B[0] == 9) ? 1 : 0)
# define ISDEL(B) ((B[0] == 127) ? 1 : 0)
# define ISSPACE(B) ((B[0] == 32) ? 1 : 0)
# define ISRETURN(B) ((B[0] == 10) ? 1 : 0)
# define ISCTRLBACKSLASH(B) ((B[0] == 28) ? 1 : 0)
# define ISCTRLA(B) ((B[0] == 1) ? 1 : 0)
# define ISCTRLC(B) ((B[0] == 3) ? 1 : 0)
# define ISCTRLD(B) ((B[0] == 4) ? 1 : 0)
# define ISCTRLE(B) ((B[0] == 5) ? 1 : 0)
# define ISCTRLF(B) ((B[0] == 6) ? 1 : 0)
# define ISCTRLO(B) ((B[0] == 15) ? 1 : 0)
# define ISCTRLZ(B) ((B[0] == 26) ? 1 : 0)

struct termios		oldterm;
struct termios		newterm;

typedef	struct		s_attr
{
	char			*bc;
	char			*ch;
	char			*cm;
	char			*cr;
	char			*cv;
	char			*ll;
	char			*nw;
	char			*pc;
	char			*up;
	char			*ci;
	char			*sf;
	char			*se;
	char			*uc;
	char			*dm;
	char			*nd;
	char			*ei;
	char			*mb;
	char			*md;
	char			*mk;
	char			*reinit_cursor;
	char			*clear_line;
	char			*clear_till_end_of_screen;
	char			*blinking_mode;
	char			*init_sequential_output;
	char			*init_random_cursor_motion;
	char			*clear_up;
	char			*cursornormal;
	char			*delchar;
	char			*down;
	char			*highlight;
	char			*highlightoff;
	char			*invisiblecursor;
	char			*left;
	char			*right;
	char			*topleft;
	char			*underlined;
	char			*underlined_off;
	char			*insert_char;
	char			*delete_char;
	char			*delete_chars;
	int				autowrap;
	char			*resetcursor;
	char			*savecursor;
	int				height;
	int				width;
	int				footer;
}					t_attr;

t_attr				*g_attr;

int					get_term_entry();
void				at_exit(t_attr *g_attr, int g_pid);
void				clearline(t_attr *g_attr);
void				clear_up(t_attr *g_attr);
void				clear_display(t_attr *g_attr);
void				deletescreen(t_attr *g_attr);
void				display_time(t_attr *g_attr);
void				display_time_loop();
void				t_put_xy(int x, int y, char *str, t_attr *g_attr);
void				highlight(t_attr *g_attr);
void				highlightoff(t_attr *g_attr);
void				init_signals();
void				new_line(t_attr *g_attr);
void				put_highlighted(char *str, t_attr *g_attr);
void				put_underlined(char *str, t_attr *g_attr);
void				init_sequential_output(t_attr *g_attr);
void				init_random_cursor_motion(t_attr *g_attr);
void				start_of_line(t_attr *g_attr);
void				switch_to_canonical();
void				underlined(t_attr *g_attr);
void				underlined_off(t_attr *g_attr);
void				top_left(t_attr *g_attr);
void				t_put(char *str);
void				turn_cursor_invisible(t_attr *g_attr);
void				window_management(t_attr *g_attr);
int					clock_fork(int *g_pid, t_attr *g_attr);
t_attr				*term_init(void);
void				term_reset(t_attr *g_attr);
void				delete_char(t_attr *g_attr);
void				delete_chars();
void				insert_char(t_attr *g_attr);
void				go_left(t_attr *g_attr);
void				go_right(t_attr *g_attr);
t_attr				*load_attributes(t_attr *g_attr);
void				ft_put_tty(char c);
void				reinit_init(t_attr *g_attr);
void				reinit_cursor(t_attr *g_attr);
void				put_underlined_highlighted(char *str, t_attr *g_attr);
#endif
