/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 13:58:23 by yzaim         #+#    #+#                 */
/*   Updated: 2023/10/29 16:57:41 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main/minishell.h"

//remove mini variable if not used!
void	ft_command_not_found(t_var *mini, char *cmd)
{
	ft_putstr_fd(MSG_EMPTY, STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	ft_free_all(mini);
	exit (127);
}

void	ft_permission_denied(t_var *mini, char *cmd)
{
	ft_putstr_fd(MSG_EMPTY, STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": Permission denied\n", STDERR_FILENO);
	ft_free_all(mini);
	exit (126);
}
