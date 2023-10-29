/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 14:30:46 by yzaim         #+#    #+#                 */
/*   Updated: 2023/10/29 17:32:40 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main/minishell.h"

int	ft_free_pipes(int **pipes, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(pipes[i]);
		i++;
	}
	free(pipes);
	return (EXIT_SUCCESS);
}

int	ft_free_cmd_struct(t_cmd *cmd)
{
	if (cmd->full_cmd)
		ft_free_double((void **) cmd->full_cmd, -1);
	if (cmd->n_redirect)
		free(cmd->redirections);
	if (cmd->files)
		ft_free_double((void **) cmd->files, -1);
	return (EXIT_SUCCESS);
}

int	ft_free_cmd_arr(t_var *mini)
{
	uint32_t	i;

	i = 0;
	while (i < mini->n_cmd)
	{
		ft_free_cmd_struct(mini->cmd_data + i);
		i++;
	}
	free(mini->cmd_data);
	mini->cmd_data = NULL;
	mini->n_cmd = 0;
	return (EXIT_SUCCESS);
}

int	ft_free_env_list(t_var *mini)
{
	t_env	*tmp;
	t_env	**env_list;

	if (!mini->env_list)
		return (EXIT_SUCCESS);
	env_list = mini->env_list;
	while (*env_list != NULL)
	{
		tmp = *env_list;
		*env_list = (*env_list)->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
	free(env_list);
	return (EXIT_SUCCESS);
}
