#include "main.h"

/**
 * hndlePrntFuncDaf - Prints
 * @format: Formatted
 * @ind: in
 * @width: get
 * Return: 1 or 2;
 */

int hndlePrntFuncDaf(const char *format, int *ind, int width)
{
	int unknwnlen = 0, res;

	if (format[*ind] == '\0')
		return (-1);
	unknwnlen += write(1, "%%", 1);
	if (format[*ind - 1] == ' ')
		unknwnlen += write(1, " ", 1);
	else if (width)
	{
		--(*ind);
		while (format[*ind] != ' ' && format[*ind] != '%')
			--(*ind);
		if (format[*ind] == ' ')
			--(*ind);
		res = (1);
	}
	unknwnlen += write(1, &format[*ind], 1);
		res = (unknwnlen);
	return (res);
}

/* DONE 6 .......................... END ..........................6..*/


/* DONE 5 .......................... START ..........................5..*/

/**
 * hWriteChar - Prints
 * @c: char
 * @buffer: Buffer
 * @flgs: Calculates
 * @width: get
 * @presn: presn
 * @size: Size
 *
 * Return: Number of chars prntd.
 */

int hWriteChar(char c, char buffer[],
					  int flgs, int width, int presn, int size)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0, res;
	char padd = ' ';

	NOT_USED(presn), NOT_USED(size);

	if (flgs & ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		res = hWriteCharDaf(buffer, flgs, width, padd);
		return (res);
	}
	res = write(1, &buffer[0], 1);
	return (res);
}


/**
 * hWriteCharDaf - Prints
 * @buffer: Buffer
 * @flgs: Calculates
 * @width: Size
 * @padd: char
 *
 * Return: Number of chars prntd.
 */

int hWriteCharDaf(char buffer[], int flgs, int width, char padd)
{
	int i = 0, res;

	buffer[BUFFER_SIZE - 1] = '\0';
	for (i = 0; i < width - 1; i++)
		buffer[BUFFER_SIZE - i - 2] = padd;

	if (flgs & MINUS)
		res = (write(1, &buffer[0], 1) +
				write(1, &buffer[BUFFER_SIZE - i - 1], width - 1));
	else
		res = (write(1, &buffer[BUFFER_SIZE - i - 1], width - 1) +
				write(1, &buffer[0], 1));

	return (res);
}
