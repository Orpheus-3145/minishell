/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_paths.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: yzaim <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/26 13:48:59 by yzaim         #+#    #+#                 */
/*   Updated: 2023/10/29 17:29:11 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main/minishell.h"

char	*ft_find_path(t_var *mini)
{
	t_env	*env_list;

	if (!mini->env_list)
		return (NULL);
	env_list = *(mini->env_list);
	while (env_list)
	{
		if (!ft_strncmp(env_list->key, "PATH", 4))
			return (env_list->value);
		env_list = env_list->next;
	}
	return (NULL);
}

void	ft_split_path(t_var *mini)
{
	char	*path_value;

	path_value = ft_find_path(mini);
	if (path_value)
	{
		mini->paths = ft_split(path_value, ':', false);
		if (!mini->paths)
		{
			ft_free_double((void **) mini->paths, -1);
			kill_program(mini);
		}
		return ;
	}
	mini->paths = NULL;
}
