# Minishell
The idea of the project is to create a new shell, able to execute commands, manage environment variables, ...
This shell is directly inspired to the Bash shell and behaves like it as much as possibile, specifically the one used on UNIX (OS X).

Minishell was a project developed by my team-partner [ys_zm](https://github.com/ys-zm) ( <--- many thanks for the cooperation!) and me.

# Overview
See the [subject](https://cdn.intra.42.fr/pdf/pdf/99970/en.subject.pdf) of the project for the specific guidelines, but substantially minishell behaves as Bash

## 1. sintax
- Unclosed quotes are treated as sintax-errors
- characters **'\\'** and **';'** are not considered meta-characters and have no consequence
- operations **&&** and **||** are not implemented

## 2. signals
the signals interally implemented are:
- SIG_INT (CTRL C)  -- interrupts the running command prints an empty prompt;
- SIG_INT (CTRL C)  -- interrupts the running command prints an empty prompt;
- EOF (CTRL D)      -- exits the shell.

## 3. builtins
Some commands was directly implemented in the shell at C level (a.k.a. builtins), the others are executed as usual looking for the executable inside the **$PATH** variable.
The builtins are: (only the options inside the parenthesis are admitted)  
- **echo** (only option -n);
- **cd** (with only a relative or absolute path);
- **pwd** (no options);
- **export** (no options);
- **unset** (no options);
- **env** (no options or arguments);
- **exit** (no options).

## 4. redirections
The IO redirections are treated as follows:
- **<**   --  *single input redirection* ;
- **>**   --  *single output redirection* ;
- **<<**  --  *double input redirection* or here_doc mode;
- **>>**  --  *double output redirection* or append mode.

# Approach
The whole workload was splitted into two main parts:
1. **parsing**: (in which the undersigned was involved) it consists of refining the input throught the following steps
	- **parser**: a string is read for the input prompt (input operation realy on readline C-library) and also the sintax is checked;
	- **expander**: variable expansion (*variables inside single quotes are not expanded*);
	- **tokenizer**: the imput is splitted into single commands (if there are pipes) and then into single tokens;
	- **lexer**: the tokens are classified into categories, such as *main command*, *options*, *redirections*, ... .

# Code
The project is written in C, according to the [Norm](https://meta.intra.42.fr/articles/the-norm-v4), and it is compiled with the flags:
- -Werror
- -Wextra
- -Wall
- -fsanitize=address

**N.B.** sometimes (inside Linux environment especially) the program might fail when exited, because of some leaks caused by the C function readline().

## Compiling and running:
The project relies on a submodule ([Libft](https://github.com/Orpheus-3145/Libft)) for low level C operations.
1. `make`    creates the executable;
1. `make run`    calls `make` and runs the executable;
1. `make clean`    removes object files;
1. `make fclean`    calls `make clean` and removes the executable;
1. `make re`    calls `make fclean` and then `make`;

## Structure:
	include/           <- header file
	libft/             <- auxiliary submodule 
	objects/           <- object files
	sources/           <- source C files
		builtins/		<- builtins commands
		checker/		<- checks to perform on the input sequence command
		env/			<- handling of environment variables
		error_handling/		<- errors and destructors
		exec/			<- executor part (after parser-lexer-expander)
		here_doc/		<- handling the here_doc (multiline input redirection)
		lexer/			<- last phase of the parsing the command is tokenized
		main/			<- main function and signal handling
		parser/			<- first phase: input storing, checks and variable expansion
		utils/			<- generic use functions

# References
- 42 project: [minishell](https://cdn.intra.42.fr/pdf/pdf/99970/en.subject.pdf)
- By: Francesco Aru ([GithHub](https://github.com/Orpheus-3145)) and [ys_zm](https://github.com/ys-zm), francesco.aru25@gmail.com, intra42/slack nickname: @faru, Codam, Amsterdam