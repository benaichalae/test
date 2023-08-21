#include "shell.h"

char **tokenizer(char *line)
{
    char *token = NULL, *temp = NULL;
    char **cmd = NULL;
    int counter = 0, i = 0;

    if (!line)
        return (NULL);
    temp = _strdup(line);
    token = strtok(temp, DELIM);
    if (token == NULL)
    {
        free(temp);
        free(line);
        return (NULL);
    }
    while (token)
    {
        counter++;
        token = strtok(NULL, DELIM);
    }
    free(temp);

    cmd = malloc(sizeof(char *) * (counter + 1));
    if (!cmd)
    {
        free(line);
        return (NULL);
    }

    token = strtok(line, DELIM);
    while (token)
    {
        cmd[i] = _strdup(token);
        token = strtok(NULL, DELIM);
        i++;
    }
    free(line);
    cmd[i] = NULL;
    return (cmd);
}