#include "shell.h"

void free_array(char **arr)
{
	int i;

	if (arr == NULL)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr);
}