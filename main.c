#include "shell.h"

/**
 * main - simple shell main function
 * @ac: count of arguments
 * @av: arguments
 * Return: 0 always
*/

int main(int ac, char **argv)
/**{
    char *line = NULL, **cmd = NULL;
    int status = 0;
    (void) ac;

    while (1)
    {
        line = read_line();
        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return (status);
        }
        cmd = tokenizer(line);
        if (cmd == NULL)
            continue;
        else
            status = _execute(cmd, argv);
    }
}*/
{
    char **cmd;
    int status = 0, i;
    (void) ac;
    
    while (1) {
        char *input = read_line();

        if (input == NULL)
            break;

        cmd = tokenizer(input);

        if (cmd != NULL) {
            status = _execute(cmd, argv);
            for (i = 0; cmd[i] != NULL; i++) {
                free(cmd[i]);
            }
            free(cmd);
        }

        free(input);
    }

    return status;
}