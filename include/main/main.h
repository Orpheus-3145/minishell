/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fra <fra@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/01 02:00:55 by fra           #+#    #+#                 */
/*   Updated: 2023/10/29 16:58:41 by fra           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

// main.c
void	set_up_struct(t_var **mini, char **envp);

void	ft_set_home(t_var *mini);

void	exit_shell(char *input);

void	main_loop(t_var	*main_var);

//signals.h
void	init_sig_handle(t_sig_mode mode);

void	signal_handler(int signum);

#endif
