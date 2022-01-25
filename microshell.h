#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <fctnl.h>

typedef struct  s_cmd
{
    int tube[2];
    char *cmd;
    char **cmd_args;
    t_cmd *next;
}   t_cmd;

typedef struct s_params
{
    t_cmd *cmd_lst;
    
    char **argv;
}   t_params ;

#endif