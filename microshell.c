#include  "microshell.h"

int parse_args(int argc, char **argv, t_cmd *cmd_lst)
{
    int i;
    char *current_arg;

    i = 1;
    while (i < argc)
    {
        current_arg = argv[i];
        if (!strncmp(current_arg, "/", 1))
            cmd_lst->cmd = argv[i];
        if (!strcmp(current_arg, "|"))
            cmd_lst->previous
        i++;
    }
}


int main(int argc, char **argv, char **envp)
{
    t_cmd   *cmd_lst;

    if(parse_args(argc, argv, cmd_lst))
        write(2, "Arguments Error\n", 16);

    return (0);    
}