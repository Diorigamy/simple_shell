#include "shell.h"
/**
 * buffer_reallocate - reallocs memory
 * @b: buffer structure
 */
void buffer_reallocate(buffer *b)
{
	char *tempbuf;

	tempbuf = b->buf;
	b->size *= 2;
	b->buf = safe_malloc(sizeof(char) * b->size);
	_memcpy(b->buf, tempbuf, b->size / 2);
	_free(tempbuf);
}
/**
 * buffer_word_erase - overwrites word
 * @b: pointer
 * @n: position overwriting starts
 */
void buffer_word_erase(buffer *b, int n)
{
	int a = 0;

	while (!(_is_whitespace(b->buf[n + a]) || _is_endofcmd(b->buf[n + a])))
	{
		b->buf[n + a] = ' ';
		a++;
	}
}
/**
 * buffer_insert - inserts string in the buffer
 * @b: pointer
 * @s: string to be inserted
 * @n: position to insert
 */
void buffer_insert(buffer *b, char *s, int n)
{
	unsigned int i, total_len, s_len;
	int j;

	buffer_word_erase(b, n);

	i = 0;
	while (_is_whitespace(b->buf[n + i]) && (n + i) < b->size)
		i++;
	s_len = _strlen(s);
	if (i >  s_len)
		;
	else
	{
		total_len = b->bp;
		total_len += _strlen(b->buf + b->bp);
		total_len += s_len;
		while (total_len > b->size)
			buffer_reallocate(b);
		for (j = 0; b->buf[j + n] != '\0'; j++)
			;
		for ( ; j >= 0; j--)
			b->buf[j + n + s_len - i + 1] = b->buf[j + n];
	}
	i = 0;
	while (s[i] != '\0')
		b->buf[n + i] = s[i], i++;
}
