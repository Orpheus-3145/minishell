/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signals.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: faru <faru@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/28 11:57:18 by faru          #+#    #+#                 */
/*   Updated: 2023/10/28 21:42:22 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell/minishell.h"

void	init_shell_envioment(void)
{
	struct termios	attributes;

	tcgetattr(STDIN_FILENO, &attributes);
	attributes.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &attributes);
}

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		*g_exit_code = 130;
	}
}

void	init_sig_handle(t_sig_mode mode)
{
	if (mode == SIG_STD_HANDLE)
	{
		init_shell_envioment();
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mode == SIG_MAIN_HANDLE)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mode == SIG_CHILD_HANDLE)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (mode == SIG_HD_CHILD_HANDLE)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_IGN);
	}
}
