#include "main.h"

/**
 * error_env - error message for env in get_env.
 * @datash: data relevant (counter, arguments)
 * Return: error message.
 */
char *error_env(data_shell *datash)
{
	int scope;
	char *error;
	char *ver_str;
	char *message;

	ver_str = aux_itoa(datash->counter);
	message = ": Unable to add/remove from environment\n";
	scope = _strscp(datash->av[0]) + _strscp(ver_str);
	scope += _strscp(datash->args[0]) + _strscp(message) + 4;
	error = malloc(sizeof(char) * (scope + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, message);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * error_path_126 - error message for path and failure denied permission.
 * @datash: data relevant (counter, arguments).
 *
 * Return: The error string.
 */
char *error_path_126(data_shell *datash)
{
	int scope;
	char *ver_str;
	char *error;

	ver_str = aux_itoa(datash->counter);
	scope = _strscp(datash->av[0]) + _strscp(ver_str);
	scope += _strscp(datash->args[0]) + 24;
	error = malloc(sizeof(char) * (scope + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}
