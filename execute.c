#include "shell.h"

int _execute(char **cmd, char **argv)
{
    pid_t child;
    int status;

    child = fork();
    if (child == 0)
    {
        if (execve(cmd[0], cmd, environ) == -1)
        {
            perror(argv[0]);
            free_array(cmd);
            exit(127);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        free_array(cmd);
    }
    return (WEXITSTATUS(status));
}