#include "shell.h"

char *read_line(void)
/**{
    char *line = NULL;
    size_t len = 0;
    ssize_t n;

    if (isatty(STDIN_FILENO) == 1)
        write(STDOUT_FILENO, "$ ", 2);
    n = getline(&line, &len, stdin);
    if (n == -1)
    {
        free(line);
        return (NULL);
    }
    return (line);
}*/
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t n;

    if (isatty(STDIN_FILENO)) {
        write(STDOUT_FILENO, "$ ", 2);
        fflush(stdout);
    }

    n = getline(&line, &bufsize, stdin);

    if (n == -1 || (n == 0 && line[0] == '\n')) {
        free(line);
        return NULL;
    }

    return line;
}