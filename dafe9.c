#include "main.h"

/* DONE 2 .......................... END ..........................2..*/

/* DONE 1 .......................... START ..........................1..*/
/**
 * wrtePtr - Write
 * @buffer: Arrays
 * @ind: Index
 * @len: len
 * @width: Wwidth
 * @flgs: Flgs
 * @padd: Char
 * @extra_c: Char
 * @padd_start: Index
 *
 * Return: Number
 */
int wrtePtr(char buffer[], int ind, int len,
				  int width, int flgs, char padd, char extra_c, int padd_start)
{
	int i, chk, res;

	if (width > len)
	{
		for (i = 3; i < width - len + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flgs & MINUS && padd == ' ') /* Asign extra char to left of buffer */
		{
			chk = 1;
			res = bufffuncDaf(buffer, ind, extra_c, i, len, chk);
			return (res);
		}

		else if (!(flgs & MINUS) && padd == '0') /* extra char to left of padd */
		{
			res = bufffuncDaf2(buffer, ind, extra_c, i, len, padd_start);
			return (res);
		}

		else if (!(flgs & MINUS) && padd == ' ') /* extra char to left of buffer */
		{
			chk = 3;
			res = bufffuncDaf(buffer, ind, extra_c, i, len, chk);
			return (res);
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;

	res = write(1, &buffer[ind], BUFFER_SIZE - ind - 1);
	return (res);
}

/**
 * bufffuncDaf - Write
 * @buffer: Arrays
 * @ind: Index
 * @len: len
 * @i: Flgs
 * @chk: Flgs
 * @extra_c: Char
 *
 * Return: Number
 */
int bufffuncDaf(char buffer[], int ind, char extra_c, int i, int len, int chk)
{
	int num;

	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;

	if (chk == 1)
		return (write(1, &buffer[ind], len) + write(1, &buffer[3], i - 3));
	else if (chk == 3)
		num = 3;
	return (write(1, &buffer[num], i - 3) + write(1, &buffer[ind], len));
}

/**
 * bufffuncDaf2 - Write
 * @buffer: Arrays
 * @ind: Index
 * @len: len
 * @i: Flgs
 * @extra_c: Char
 * @padd_start: Index
 *
 * Return: Number
 */
int bufffuncDaf2(char buffer[], int ind, char extra_c, int i,
					int len, int padd_start)
{
	if (extra_c)
		buffer[--padd_start] = extra_c;
	buffer[1] = '0';
	buffer[2] = 'x';
	return (write(1, &buffer[padd_start], i - padd_start) +
			write(1, &buffer[ind], len - (1 - padd_start) - 2));
}

/* DONE 1 ................... END ...................................1..*/

/**
 * isPrntble - Evaluate
 * @c: Cha
 * Return: 1
 */
int isPrntble(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * appndHexCode - Append
 * @buffer: Array
 * @i: Index
 * @ascii_code: ASSCI
 * Return: 3
 */
int appndHexCode(char ascii_code, char buffer[], int i)
{
	int num;
	char map_to[] = "0123456789ABCDEF";

	num = 3;
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (num);
}
