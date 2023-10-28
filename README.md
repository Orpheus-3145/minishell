# Minishell
The idea of the project is to create a new shell, able to run commands, manage environment variables, ...
This shell is directly inspired to the Bash shell and behaves like it as much as possibile, specifically the one used on UNIX (OS X).

Minishell was a project developed by my team-partner [ys_zm](https://github.com/ys-zm) ( <--- many thanks for the cooperation!) and me.


# Overview
Substantially minishell behaves as Bash but with the following semplifications:
## sintax
Unclosed quotes are treated as sintax-errors
characters *\\* and *;* are not considered meta-characters and have no consequence
operations *&&* and *||* are not implemented

## signals
the signals interally implemented are:
- SIG_INT (CTRL C)  -- interrupts the running command prints an empty prompt
- SIG_INT (CTRL C)  -- interrupts the running command prints an empty prompt
- EOF (CTRL D)  -- exits the shell





# Approach


# Code
The project is written in C, according to the Norm (<<LINK>>), and it is compiled with the flags:
- -Werror
- -Wextra
- -Wall
- -fsanitize=address

## Compiling and running:
The project relies on a submodule ([Libft](https://github.com/Orpheus-3145/Libft)) for low level C operations
1. `make`    creates the executable;
1. `make clean`    removes object files;
1. `make fclean`    calls `make clean` and removes the executable;
1. `make re`    calls `make fclean` and then `make`;

## Structure:
    include/           <- header file
    libft/             <- auxiliary submodule 
    objects/           <- object files
    sources/           <- source C files
            init.c    <- initialization of structs for container and philosophers
            main.c    <- main program, check-parse-simulation
            mutex.c   <- wrappers to access protected variables
            threads.c <- thread functions
            tools.c   <- non-specific functions

# References
- 42 project: [minishell](https://cdn.intra.42.fr/pdf/pdf/99970/en.subject.pdf)
- By: Francesco Aru ([GithHub](https://github.com/Orpheus-3145)), [ys_zm](https://github.com/ys-zm), francesco.aru25@gmail.com, intra42/slack nickname: @faru, Codam, Amsterdam