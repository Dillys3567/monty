#include <stdlib.h>

char *get_int(int n);
unsigned int _abs(int);
int get_num_len(unsigned int n, unsigned int base);
void fill_base_buff(unsigned int n, unsigned int base, char *buff
		, int buff_size);

/**
 * get_int - get char pointer to string with int
 * @n: number
 * Return: char to new string
 */
char *get_int(int n)
{
	unsigned int t;
	int len = 0;
	long num = 0;
	char *ret;

	t = _abs(n);
	len = get_num_len(t, 10);
	if (n < 0 || num < 0)
		len++;
	ret = malloc(len + 1);
	if (!ret)
		return (NULL);
	fill_base_buff(t, 10, ret, len);
	if (n < 0 || num < 0)
		ret[0] = '-';
	return (ret);
}
/**
 * _abs - absolute value
 * @x: integer
 * Return: absolute value
 */
unsigned int _abs(int x)
{
	if (x < 0)
		return (-(unsigned int)x);
	return ((unsigned int)x);
}
/**
 * get_num_len - get buffer length
 * @n: number to get length
 * @base: base of number
 * Return: int of length
 */
int get_num_len(unsigned int n, unsigned int base)
{
	int len = 1;

	while (n > base - 1)
	{
		len++;
		n /= base;
	}
	return (len);
}
/**
 * fill_base_buff - fill buffer with bases
 * @n: number
 * @base: base of number
 * @buff: buffer
 * @buff_size: size of buffer
 */
void fill_base_buff(unsigned int n, unsigned int base, char *buff
		, int buff_size)
{
	int rem, x = buff_size - 1;

	buff[buff_size] = '\0';
	while (x >= 0)
	{
		rem = n % base;
		if (rem > 9)
			buff[x] = rem + 87;
		else
			buff[x] = rem + '0';
		n /= base;
		x--;
	}
}
