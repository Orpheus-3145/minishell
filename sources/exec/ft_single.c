/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_single.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 13:54:26 by yzaim         #+#    #+#                 */
/*   Updated: 2023/10/29 16:57:41 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main/minishell.h"

int	ft_sig_check(int exit_status)
{
	if (WIFSIGNALED(exit_status))
	{
		if (WTERMSIG(exit_status) == SIGINT)
			return (130);
		if (WTERMSIG(exit_status) == SIGQUIT)
			return (131);
	}
	return (EXIT_FAILURE);
}

int	single_cmd(t_var *mini)
{
	t_cmd	*cmd;
	int		exit_status;

	cmd = mini->cmd_data;
	if (!cmd->cmd_name)
		return (ft_redir_type(mini, 0), EXIT_SUCCESS);
	if (ft_if_builtin(cmd->cmd_name))
		return (ft_run_builtin(mini));
	init_sig_handle(SIG_MAIN_HANDLE);
	(mini)->f_pid = fork();
	if ((mini)->f_pid < 0)
		return (ft_error_msg("Fork failed"), 1);
	if (mini->f_pid == 0)
	{
		init_sig_handle(SIG_CHILD_HANDLE);
		ft_exec_child_single(mini);
	}
	waitpid(mini->f_pid, &exit_status, 0);
	init_sig_handle(SIG_STD_HANDLE);
	if (WIFEXITED(exit_status))
		return (WEXITSTATUS(exit_status));
	return (ft_sig_check(exit_status));
}
