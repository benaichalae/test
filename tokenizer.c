#include "shell.h"

char **tokenizer(char *line)
/**{
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
}*/
{
    char **tokens = NULL;
    char *token = NULL;
    int token_count = 0;
    int token_size = 1;
    
    tokens = (char **)malloc(sizeof(char *) * token_size);
    if (tokens == NULL)
        return (NULL);

    token = strtok(line, DELIM);
    while (token != NULL)
    {
        tokens[token_count] = _strdup(token);
        if (tokens[token_count] == NULL)
        {
            for (int i = 0; i < token_count; i++)
            {
                free(tokens[i]);
            }
            free(tokens);
            return (NULL);
        }

        token_count++;
        if (token_count >= token_size)
        {
            token_size *= 2;
            tokens = (char **) _realloc(tokens, sizeof(char *) * token_size, sizeof(char *) * token_size);
            if (tokens == NULL)
                return (NULL);
        }

        token = strtok(NULL, DELIM);
    }

    tokens[token_count] = NULL;

    return (tokens);
}