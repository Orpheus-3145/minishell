/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/04 02:32:32 by fra           #+#    #+#                 */
/*   Updated: 2023/10/29 17:02:13 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "main/minishell.h"

int	*g_exit_code;

void	exit_shell(char *input)
{
	if (has_trailing_pipe(input) == true)
		ft_putstr_fd(MSG_SINTAX_ERROR, 2);
	else
		ft_putstr_fd(MSG_EXIT, 2);
	free(input);
}

void	main_loop(t_var *mini)
{
	t_cmd_status	status;
	char			*input;

	while (true)
	{
		input = NULL;
		status = aquire_input(&input, mini);
		if ((status == CMD_MEM_ERR) || (status == CMD_FILE_ERR) || (status == CMD_PROC_ERR))
			kill_program(mini);
		else if (status == CMD_CTRL_D)
		{
			exit_shell(input);
			break ;
		}
		if (ft_is_empty_str(input) == false)
			add_history(input);
		if (status == CMD_OK)
			run_cmd(input, mini);
		else
			free(input);
		if (status == CMD_SIN_ERR)
			ft_putstr_fd(MSG_SINTAX_ERROR, 2);
	}
	clear_history();
}

void	set_up_struct(t_var **mini, char **envp)
{
	init_sig_handle(SIG_STD_HANDLE);
	*mini = ft_calloc(1, sizeof(t_var));
	if (*mini == NULL)
		kill_program(*mini);
	(*mini)->cmd_data = NULL;
	(*mini)->n_cmd = 0;
	(*mini)->env_list = NULL;
	(*mini)->env_arr = NULL;
	(*mini)->paths = NULL;
	if (envp && *envp)
		make_env_list(envp, *mini);
	(*mini)->hd_path = getcwd(NULL, 0);
	if ((*mini)->hd_path == NULL)
		kill_program(*mini);
	else
		ft_set_shlvl(*mini);
}

int	main(int argc, char **argv, char **envp)
{
	t_var	*mini;

	(void)argv;
	if (argc > 1)
		ft_putstr_fd(MSG_UNN_ARGUMENT, 2);
	set_up_struct(&mini, envp);
	g_exit_code = &mini->status;
	main_loop(mini);
	ft_free_all(mini);
	return (mini->status);
}
