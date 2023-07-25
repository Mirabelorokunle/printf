#include "main.h"

/**
 * isDigit - Verifies
 * @c: Char
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int isDigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);

	return (0);
}

/**
 * convtSizeNum - Casts
 * @num: Number
 * @size: Number
 *
 * Return: Casted
 */
long int convtSizeNum(long int num, int size)
{
	if (size == LONG)
		return (num);
	else if (size == SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * cSizeUsignd - Casts
 * @num: Number
 * @size: Number
 *
 * Return: Casted
 */
long int cSizeUsignd(unsigned long int num, int size)
{
	if (size == LONG)
		return (num);
	else if (size == SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
