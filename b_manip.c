#include "shell.h"
/**
 * brocate - resize and copy over into new buffer space
 * @b: pointer to buffer structure
 */
void brocate(ctrl_buf *b)
{
	char *tbuf;

	tbuf = b->ptr;
	b->buff *= 2;
	b->ptr = maloc(sizeof(char) * b->ptr);
	mcpy(b->ptr, tbuf, b->buff / 2);
	fr(tbuf);
}
/**
 * berase - overwrite word from n to first whitespace
 * @b: pointer to buffer structure
 * @n: position to overwrite from
 * Description: If b->buf[n] is not pointing at a legal command character,
 *				function will do nothing. Otherwise overwrites word.
 */
void berase(ctrl_buf *b, int n)
{
	int x;

	x = 0;
	while (!(chesp(b->curr[n + x]) || cmend(b->curr[n + x])))
	{
		b->curr[n + x] = ' ';
		x++;
	}
}
/**
 * bins - insert string into buffer at position n
 * @b: pointer to buffer structure
 * @s: string to insert
 * @n: position to insert
 * Description: Complex calculation to move buffer for string insertion.
 *				Since all valid command replacements happen at words,
 *				function will delete word at position n, and only move
 *				buffer if there is not enough whitespace for insertion.
 */
void bins(ctrl_buf *b, char *s, int n)
{
	unsigned int i, total_len, s_len;
	int j;

	berase(b, n);

	i = 0;
	while (chesp(b->ptr[n + i]) && (n + i) < b->size)
		i++;
	s_len = slen(s);
	if (i >  s_len)
		; /* insert happens below */
	else
	{
		total_len = b->curr;
		total_len += slen(b->ptr + b->curr);
		total_len += s_len;
		while (total_len > b->buff)
			brocate(b);
		/* Find out how many chars remain in the string to move over */
		for (j = 0; b->ptr[j + n] != '\0'; j++)
			;
		/* Make room in buffer by moving chars to the right */
		/* jth char at nth position + length of the string */
		/* - total open whitespace + 1 whitespace at end of cmd */
		for ( ; j >= 0; j--)
			b->ptr[j + n + s_len - i + 1] = b->ptr[j + n];
	}
	i = 0;
	while (s[i] != '\0')
		b->ptr[n + i] = s[i], i++;
}
