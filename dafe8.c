#include "main.h"

/* DONE 5 .......................... END ..........................5..*/

/* DONE 4 .......................... START ..........................4..*/

/**
 * writeNum - Prints
 * @iNeg: Lis
 * @ind: char
 * @buffer: Buffer
 * @flgs: Calculates
 * @width: get
 * @presn: presn
 * @size: Size
 *
 * Return: Number of chars prntd.
 */
int writeNum(int iNeg, int ind, char buffer[],
				 int flgs, int width, int presn, int size)
{
	int len = BUFFER_SIZE - ind - 1, res;
	char padd = ' ', extra_ch = 0;

	NOT_USED(size);

	if ((flgs & ZERO) && !(flgs & MINUS))
		padd = '0';
	if (iNeg)
		extra_ch = '-';
	else if (flgs & PLUS)
		extra_ch = '+';
	else if (flgs & SPACE)
		extra_ch = ' ';

	res = wrteNum(ind, buffer, flgs, width, presn, len, padd, extra_ch);
	return (res);
}
/* DONE 4 .......................... END ..........................4..*/

/* DONE 3 .......................... START ..........................3..*/

/**
 * wrteNum - Write
 * @ind: Index
 * @buffer: Buff
 * @flgs: Fl
 * @width: widt
 * @prec: Presn
 * @len: Numbe
 * @padd: Pading
 * @extra_c: Extra
 *
 * Return: Number of prntd chars.
 */
int wrteNum(int ind, char buffer[],
			  int flgs, int width, int prec,
			  int len, char padd, char extra_c)
{
	int res;

	if (prec == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0) no char is prntd */
	if (prec == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < len)
		padd = ' ';
	while (prec > len)
		buffer[--ind] = '0', len++;
	if (extra_c != 0)
		len++;
	if (width > len)
	{
		res = wrteNumDaf(ind, buffer,
			  flgs, width,
			  len, padd, extra_c);
	}
	if (extra_c)
		buffer[--ind] = extra_c;

	res = write(1, &buffer[ind], len);
	return (res);
}

/**
 * wrteNumDaf - Write
 * @ind: Index
 * @buffer: Buff
 * @flgs: Fl
 * @width: widt
 * @len: Numbe
 * @padd: Pading
 * @extra_c: Extra
 *
 * Return: Number of prntd chars.
 */
int wrteNumDaf(int ind, char buffer[],
			  int flgs, int width, int len, char padd, char extra_c)
{
	int i, padd_start = 1, res;

	for (i = 1; i < width - len + 1; i++)
		buffer[i] = padd;
	buffer[i] = '\0';
	if (flgs & MINUS && padd == ' ') /* Asign extra char to left of buffer */
	{
		if (extra_c)
			buffer[--ind] = extra_c;
		res = (write(1, &buffer[ind], len) + write(1, &buffer[1], i - 1));
	}
	else if (!(flgs & MINUS) && padd == ' ') /* extra char to left of buff */
	{
		if (extra_c)
			buffer[--ind] = extra_c;
		res =  (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], len));
	}
	else if (!(flgs & MINUS) && padd == '0') /* extra char to left of padd */
	{
		if (extra_c)
			buffer[--padd_start] = extra_c;
		res =  (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], len - (1 - padd_start)));
	}
	return (res);
}

/* DONE 3 .......................... END ..........................3..*/


/* DONE 2 .......................... START ..........................2..*/

/**
 * wrteUnsgnd - Writes
 * @iNeg: Number
 * @ind: Index
 * @buffer: Array
 * @flgs: Flgs
 * @width: Width
 * @presn: Presn
 * @size: Size
 *
 * Return: Number of written chars.
 */
int wrteUnsgnd(int iNeg, int ind,
				 char buffer[],
				 int flgs, int width, int presn, int size)
{
	/* The number is stored at the bufer's right and starts at position i */
	int len = BUFFER_SIZE - ind - 1, res;
	char padd = ' ';

	NOT_USED(iNeg), NOT_USED(size);

	if (presn == 0 && ind == BUFFER_SIZE - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0) no char is prntd */

	if (presn > 0 && presn < len)
		padd = ' ';

	while (presn > len)
	{
		buffer[--ind] = '0';
		len++;
	}

	if ((flgs & ZERO) && !(flgs & MINUS))
		padd = '0';

	if (width > len)
	{
		res = wrteUnsgndDaf(ind, buffer, flgs, width, padd, len);
		return (res);
	}

	res = write(1, &buffer[ind], len);
	return (res);
}

/**
 * wrteUnsgndDaf - Writes
 * @ind: Index
 * @buffer: Array
 * @flgs: Flgs
 * @width: Width
 * @padd: Presn
 * @len: Size
 *
 * Return: Number of written chars.
 */
int wrteUnsgndDaf(int ind, char buffer[], int flgs, int width,
					char padd, int len)
{
	int i;

	for (i = 0; i < width - len; i++)
		buffer[i] = padd;

	buffer[i] = '\0';

	if (flgs & MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
	{
		return (write(1, &buffer[ind], len) + write(1, &buffer[0], i));
	}
	else /* Asign extra char to left of padding [padd>buffer]*/
	{
		return (write(1, &buffer[0], i) + write(1, &buffer[ind], len));
	}
}
