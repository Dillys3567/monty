#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);
/**
 * strtow - take string and separate words
 * @str: string to separate
 * @delims: delimiters
 * Return: 2D array of pointers
 */
char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordlen, n, x = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);
	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (x < wc)
	{
		wordlen = get_word_length(str, delims);
		if (is_delim(*str, delims))
			str = get_next_word(str, delims);
		words[x] = malloc((wordlen + 1) * sizeof(char));
		if (words[x] == NULL)
		{
			while (x >= 0)
			{
				x--;
				free(words[x]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordlen)
		{
			words[x][n] = *(str + n);
			n++;
		}
		words[x][n] = '\0';
		str = get_next_word(str, delims);
		x++;
	}
	words[x] = NULL;
	return (words);
}
/**
 * is_delim - check for delimiter
 * @ch: char
 * @delims: null terminated array
 * Return: 1 on success 0 on failure
 */
int is_delim(char ch, char *delims)
{
	int x = 0;

	while (delims[x])
	{
		if (delims[x] == ch)
			return (1);
		x++;
	}
	return (0);
}
/**
 * get_word_length - word length
 * @str: string to get word length
 * @delims: delimiter
 * Return: word length
 */
int get_word_length(char *str, char *delims)
{
	int wlen = 0, pend = 1, x = 0;

	while (*(str + x))
	{
		if (is_delim(str[x], delims))
			pend = 1;
		else if (pend)
		{
			wlen++;
		}
		if (wlen > 0 && is_delim(str[x], delims))
			break;
		x++;
	}
	return (wlen);
}
/**
 * get_word_count - get word count
 * @str: string
 * @delims: delimiters
 * Return: word count
 */
int get_word_count(char *str, char *delims)
{
	int wc = 0, pend = 1, x = 0;

	while (*(str + x))
	{
		if (is_delim(str[x], delims))
			pend = 1;
		else if (pend)
		{
			pend = 0;
			wc++;
		}
		x++;
	}
	return (wc);
}
/**
 * get_next_word - get next word
 * @str: string
 * @delims: delimiters
 * Return: pointer to first char
 */
char *get_next_word(char *str, char *delims)
{
	int pend = 0, x = 0;

	while (*(str + x))
	{
		if (is_delim(str[x], delims))
			pend = 1;
		else if (pend)
			break;
		x++;
	}
	return (str + x);
}
