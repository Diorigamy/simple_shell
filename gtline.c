#include "shell.h"
/**
 * _getline_fileread - function that reads a file
 * @b: pointer to buffer structure
 * @envp: enviornment structure variable
 * Return: 1 or 0
 */
int _getline_fileread(buffer *b, env_t *envp)
{
	int fd, a;
	char *filename, *fulfilename;

	a = b->bp;
	while (_is_whitespace(b->buf[a]))
		a++;
	if (!_str_match_tonull(b->buf + a, "simple_shell") || b->buf[a] == '\0')
		return (0);
	while (!_is_whitespace(b->buf[a]) && b->buf[a] != '\0')
		a++;
	while (_is_whitespace(b->buf[a]) && b->buf[a] != '\0')
		a++;
	if (b->buf[a] == '\0')
		fd = -1;
	else
	{
		filename = b->buf + a;
		while (!_is_whitespace(b->buf[a]) && b->buf[a] != '\0')
			a++;
		b->buf[a] = '\0';
		make_path(&fulfilename, filename, "PWD", envp);
		fd = open(fulfilename, O_RDONLY);
	}
	if (fd == -1)
	{
		history_wrapper("", envp, 'w');
		defer_free(FREE_ADDRESSES);
		_exit(1);
	}
	_getline(b, fd, envp);
	close(fd);
	return (0);
}
/**
 * _getline - reads input
 * @b: pointer
 * @fd: file to read from
 * @envp: enviornment structure
 * Return: Always 0. Exit on failure or EOF
 */
int _getline(buffer *b, int fd, env_t *envp)
{
	int offset, m;

	offset = 0, m = 0;
	while ((m = read(fd, b->buf + offset, b->size - offset)) > 0 &&
			b->buf[b->bp + offset + m - 1] != '\n')
	{
		buffer_reallocate(b);
		offset += m;
	}
	if (m == 0)
	{
		if (fd > 2)
			close(fd);
		history_wrapper("", envp, 'w');
		defer_free(FREE_ADDRESSES);
		_exit(0);
	}
	b->buf[m + offset] = '\0';
	return (0);
}
