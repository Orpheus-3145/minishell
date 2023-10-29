/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 14:14:36 by yzaim         #+#    #+#                 */
/*   Updated: 2023/10/29 17:30:35 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main/minishell.h"

void	ft_set_to_null(t_var *mini)
{
	mini->cmd_data = NULL;
	mini->paths = NULL;
	mini->env_arr = NULL;
	mini->env_list = NULL;
	mini->hd_path = NULL;
}

void	ft_free_all(t_var *mini)
{
	if (mini->cmd_data)
		ft_free_cmd_arr(mini);
	if (mini->env_list)
		ft_free_env_list(mini);
	if (mini->paths)
		ft_free_double((void **) mini->paths, -1);
	if (mini->env_arr)
		ft_free_double((void **) mini->env_arr, -1);
	free(mini->hd_path);
	ft_set_to_null(mini);
}

void	ft_error_msg(char *str)
{
	ft_putstr_fd(MSG_EMPTY, 2);
	perror(str);
}

int	kill_program(t_var *mini)
{
	remove_here_docs(mini->hd_path);
	ft_free_all(mini);
	ft_error_msg("");
	mini->status = 137;
	exit(mini->status);
}

void	ft_write_error(int fd, char *func, char *str, char *msg)
{
	ft_putstr_fd(MSG_EMPTY, fd);
	ft_putstr_fd(func, fd);
	ft_putstr_fd(": ", fd);
	if (str)
	{
		ft_putstr_fd(str, fd);
		ft_putstr_fd(": ", fd);
	}
	ft_putstr_fd(msg, fd);
	ft_putstr_fd("\n", fd);
}
