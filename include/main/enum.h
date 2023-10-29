/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enum.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/01 01:56:43 by fra           #+#    #+#                 */
/*   Updated: 2023/10/29 16:53:35 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H
# define READ						0
# define WRITE						1
# define REPLACE					2
# define APPEND						3
# define HERE_DOC_FIX				"/here_doc_"
# define PROMPT						"minishell-> "
# define MSG_EXIT                   "minishell: exit\n"
# define MSG_SINTAX_ERROR           "minishell: syntax error\n"
# define MSG_EMPTY					"minishell: "
# define MSG_UNN_ARGUMENT			"unnecessary argoment(s) provided\n"

typedef enum s_shlvl_status
{
	SET_NULL,
	SET_ZERO,
	INCREMENT,
	SET_ONE,
	OUT_OF_BOUNDS
}	t_shlvl_status;

typedef enum s_cmd_status
{
	CMD_OK,
	CMD_CTRL_C,
	CMD_CTRL_D,
	CMD_MEM_ERR,
	CMD_SIN_ERR,
	CMD_FILE_ERR,
	CMD_PROC_ERR,
}	t_cmd_status;

typedef enum s_red_type
{
	RED_IN_SINGLE,	
	RED_OUT_SINGLE,
	RED_IN_DOUBLE,
	RED_OUT_DOUBLE,
}	t_red_type;

typedef enum s_sig_mode
{
	SIG_STD_HANDLE,			// normal flow
	SIG_MAIN_HANDLE,		// main process (when forking)
	SIG_CHILD_HANDLE,		// child process (when forking)
	SIG_HD_CHILD_HANDLE,	// here_doc (child process when forking)
}	t_sig_mode;

typedef struct s_env
{
	struct s_env	*next;
	char			*key;
	char			*value;
}	t_env;

typedef struct s_cmd
{
	uint32_t			n_words;
	char				*cmd_name;
	char				**full_cmd;
	uint32_t			n_redirect;
	t_red_type			*redirections;
	char				**files;
	int32_t				fd_in;
	int32_t				fd_out;
	bool				if_next;
}	t_cmd;

typedef struct s_var
{
	t_cmd		*cmd_data;
	uint32_t	n_cmd;
	t_env		**env_list;
	char		**env_arr;
	char		**paths;
	int			pipe[2];
	pid_t		f_pid;
	int			status;
	char		*hd_path;
}	t_var;

#endif
