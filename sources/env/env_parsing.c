/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_parsing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 14:06:07 by yzaim         #+#    #+#                 */
/*   Updated: 2023/10/29 16:57:41 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main/minishell.h"

void	ft_update_shell(t_env **env_list)
{
	t_env	*env;
	t_env	*start;
	char	*cwd;

	start = *env_list;
	env = *env_list;
	cwd = getcwd(0, 0);
	while (env)
	{
		if (!ft_strncmp("SHELL", env->key, 5))
		{
			free(env->value);
			env->value = cwd;
			return ;
		}
		env = env->next;
	}
	env_list = &start;
	free(cwd);
}

void	ft_free_prev(t_env *head)
{
	t_env	*tmp;

	tmp = NULL;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->key);
		free(tmp->value);
		free(tmp);
	}
}

t_env	*ft_envp_node(t_var *mini, char *envp)
{
	int		pos;
	t_env	*new_node;

	pos = ft_find_first_equals(envp);
	new_node = ft_create_node(mini, envp, pos);
	return (new_node);
}

void	make_env_list(char **envp, t_var *mini)
{
	t_env	*head;
	t_env	*node;
	int		i;

	i = 1;
	mini->env_list = ft_calloc(sizeof(t_env *), 1);
	if (!mini->env_list)
		kill_program(mini);
	head = ft_envp_node(mini, envp[0]);
	if (!head)
		kill_program(mini);
	node = head;
	while (envp[i])
	{
		node->next = ft_envp_node(mini, envp[i]);
		if (!node->next)
		{
			ft_free_prev(head);
			kill_program(mini);
		}
		node = node->next;
		i++;
	}
	*(mini->env_list) = head;
	ft_update_shell(mini->env_list);
}
