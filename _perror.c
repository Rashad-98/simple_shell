#include "main.h"

/**
 * _perror - prints error to stdout
 * @s_info: structure holding information about current shell prcess
 * @msg: error message
 */
void _perror(shell_info *s_info, char *msg)
{
	size_t prog_len, cmd_len, arg_len, msg_len;
	static int count = 1;
	char *count_str;
	char *buff;
	int cursor = 0;

	prog_len = _strlen(s_info->argv[0]);
	cmd_len = _strlen(s_info->command->argv[0]);
	arg_len = _strlen(s_info->command->argv[1]);
	msg_len = _strlen(msg);

	buff = malloc(sizeof(*buff) * (prog_len + cmd_len + arg_len + msg_len + 10));
	_strcpy(buff, s_info->argv[0]);
	_strcpy(buff + prog_len, ": ");
	cursor = prog_len + 2;
	count_str = int_to_str(count);
	_strcpy(buff + cursor, count_str);
	free(count_str);
	cursor += _strlen(count_str) + 1;
	_strcpy(buff + cursor, ": ");
	cursor += 2;
	_strcpy(buff + cursor, s_info->command->argv[0]);
	cursor += cmd_len;
	_strcpy(buff + cursor, ": ");
	cursor += 2;
	_strcpy(buff + cursor, msg);
	cursor += msg_len;
	_strcpy(buff + cursor, ": ");
	cursor += 2;
	_strcpy(buff + cursor, s_info->command->argv[1]);
	cursor += arg_len;
	_strcpy(buff + cursor, "\n");
	write(2, buff, _strlen(buff));
	free(buff);
	count++;
}
