#include  "microshell.h"

int    add_args(t_cmd **cmd_lst, char *cmd_arg)
{
    t_cmd   *current = *cmd_lst;
    int     nb_args;
    char    **tmp;

    while (current->next)
        current = current->next;
    if (!current->cmd_args)
    {
        current->cmd_args = malloc(sizeof(char *) * 2);
        if (!current->cmd_args)
            return (0);
        current->cmd_args[0] = cmd_arg;
        current->cmd_args[1] = NULL;
    }
    else
    {
        nb_args = 0;
        while ((current->cmd_args)[nb_args])
            nb_args++;
        tmp = malloc(sizeof(char *) * (nb_args + 2));
        if (!tmp)
            return (0);
        nb_args = 0;
        while ((current->cmd_args)[nb_args])
        {
            tmp[nb_args] = (current->cmd_args)[nb_args];
            nb_args++;
        }
        tmp[nb_args] = cmd_arg;
        tmp[nb_args + 1] = NULL;
        free(current->cmd_args);
        current->cmd_args = tmp;
    }
    return (1);
}

void    add_type(t_cmd **cmd_lst, char *type)
{
    t_cmd   *current = *cmd_lst;
    
    while (current->next)
        current = current->next;
    current->type = type;
}

int    add_cmd_to_lst(t_cmd **cmd_lst, char *cmd)
{
    t_cmd   *current = *cmd_lst;
    t_cmd   *new;
    
    new = malloc(sizeof(t_cmd));
    if (!new)
        return (0);

    new->type = "standard";
    new->cmd = cmd;
    new->cmd_args = NULL;
    new->next = NULL;
    new->previous = NULL;

    if (*cmd_lst)
    {
        
        while (current->next)
            current = current->next;
             
        current->next = new;
        new->previous = current;
    }
    else
        *cmd_lst = new;
    return (1);
}

int parse_args(int argc, char **argv, t_cmd **cmd_lst)
{
    int i;
    char *current_arg;

    i = 1;
    while (i < argc)
    {
        current_arg = argv[i];
        if (!strncmp(current_arg, "/", 1))
        {
            if(!add_cmd_to_lst(cmd_lst, current_arg))
                return (1);
        }
        else if (!strcmp(current_arg, "|"))
            add_type(cmd_lst, "pipe");
        else if (!strcmp(current_arg, ";"))
            add_type(cmd_lst, "break");
        else
        {
            if (!add_args(cmd_lst, current_arg))
                return (1);
        }
        i++;
    }
    return (0);
}

void    print_lst(t_cmd *cmd_lst)
{
    while (cmd_lst)
    {
        int i = 0;
        printf("commande: %s, type: %s\n", cmd_lst->cmd, cmd_lst->type);
        if (cmd_lst->cmd_args)
        {
            while((cmd_lst->cmd_args)[i])
            {
                printf("Argument %d: %s\n", i, (cmd_lst->cmd_args)[i]);
                i++;
            }
        }
        cmd_lst = cmd_lst->next;
    }
}

void    exec_cmds(t_cmd **cmd_lst)
{
    
}

int main(int argc, char **argv, char **envp)
{
    t_cmd   *cmd_lst;

    cmd_lst = NULL;
    if(parse_args(argc, argv, &cmd_lst))
        write(2, "Arguments Error\n", 16);
    //print_lst(cmd_lst);
    exec_cmds(&cmd_lst);

    return (0);    
}