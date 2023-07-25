#include "main.h"

/* DONE 10 .......................... END ........................10..*/

/**
 * getFlgsFunc - Calculates
 * @format: Formatted
 * @i: takes
 * Return: flas
 */

int getFlgsFunc(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8 16 */
	int j, curr_i;
	int flgs = 0;
	const char FLGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLGS_ARR[] = {MINUS, PLUS, ZERO, HASH, SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLGS_CH[j] != '\0'; j++)
			if (format[curr_i] == FLGS_CH[j])
			{
				flgs |= FLGS_ARR[j];
				break;
			}

		if (FLGS_CH[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flgs);
}


/* DONE 9 .......................... START ..........................9..*/

/**
 * getPresnFunc - Calculates
 * @format: Formatted
 * @i: List
 * @list: list
 * Return: Presn.
 */
int getPresnFunc(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1, chk, presn = -1;

	if (format[curr_i] != '.')
		return (presn);

	presn = 0;

	for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
	{
		if (isDigit(format[curr_i]))
		{
			chk = 1;
			getPresnFuncDaf(format, i, list, chk);
		}
		else if (format[curr_i] == '*')
		{
			chk = 2;
			getPresnFuncDaf(format, i, list, chk);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (presn);
}

/**
 * getPresnFuncDaf - Calculates
 * @format: Formatted
 * @i: List
 * @list: list
 * @chk: list
 * Return: Presn.
 */
void getPresnFuncDaf(const char *format, int *i, va_list list, int chk)
{
	int curr_i = *i + 1, presn = -1;

	if (chk == 1)
	{
		presn *= 10;
		presn += format[curr_i] - '0';
	}

	else
	{
		curr_i++;
		presn = va_arg(list, int);
	}
}

/* DONE 9 .......................... END ..........................9..*/

/* DONE 8 .......................... START ..........................8..*/
/**
 * getSizeFunc - Calculates
 * @format: Formatted
 * @i: List
 * Return: Presn.
 */

int getSizeFunc(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'h')
		size = SHORT;
	else if (format[curr_i] == 'l')
		size = LONG;

	if (size != 0)
		*i = curr_i;
	else
		*i = curr_i - 1;

	return (size);
}


/**
 * getWidthFunc - Calculates
 * @format: Formatted
 * @i: List
 * @list: list
 * Return: width.
 */
int getWidthFunc(const char *format, int *i, va_list list)
{
	int curr_i = 0, chk;
	int width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (isDigit(format[curr_i]))
		{
			chk = 1;
			getWidthFuncDaf(format, list, chk);
		}
		else if (format[curr_i] == '*')
		{
			chk = 2;
			getWidthFuncDaf(format, list, chk);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (width);
}
