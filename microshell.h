#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct  s_cmd t_cmd;

typedef struct  s_cmd
{
    char *type;
    char *cmd;
    char **cmd_args;
    int pipe[2];
    t_cmd *next;
    t_cmd *previous;
}   t_cmd;

typedef struct s_params
{
    t_cmd *cmd_lst;
    
    char **argv;
}   t_params ;

#endif