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
    char input[MAX_INPUT_SIZE];
    char **cmd;
    int status = 0;
    size_t input_length;

    while (1) {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "\n", 1);
        if (fgets(input, sizeof(input), stdin) == NULL)
            break;

        input_length = strlen(input);
        if (input_length > 0 && input[input_length - 1] == '\n')
            input[input_length - 1] = '\0';

        cmd = tokenize(input);

        if (cmd != NULL) 
        {
            status = _execute(cmd, argv);
            for (int i = 0; cmd[i] != NULL; i++) 
            {
                free(cmd[i]);
            }
            free(cmd);
        }
    }

    return (status);
}