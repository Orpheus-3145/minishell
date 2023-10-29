/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/17 22:02:45 by fra           #+#    #+#                 */
/*   Updated: 2023/10/29 16:55:53 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdint.h>
# include <signal.h>
# include <termios.h>
# include <sys/wait.h>
# include <errno.h>
# include <stddef.h>
# include <dirent.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "main/enum.h"
# include "builtins/builtins.h"
# include "checker/checker.h"
# include "env/env.h"
# include "error_handling/error_handling.h"
# include "exec/exec.h"
# include "here_doc/here_doc.h"
# include "lexer/lexer.h"
# include "main/main.h"
# include "parser/parser.h"
# include "utils/utils.h"

extern int	*g_exit_code;

#endif
