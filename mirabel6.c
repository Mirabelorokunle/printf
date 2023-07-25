#include "main.h"

/**
 * getWidthFuncDaf - Calculates
 * @format: Formatted
 * @chk: List
 * @list: list
 */

void getWidthFuncDaf(const char *format, va_list list, int chk)
{
	int curr_i = 0, width = 0;

	if (chk == 1)
	{
		width *= 10;
		width += format[curr_i] - '0';
	}

	else
	{
		curr_i++;
		width = va_arg(list, int);
	}
}


/* DONE 7 .......................... END ..........................7..*/


/* DONE 6 .......................... START ..........................6..*/

/**
 * hndlePrntFunc - Prints
 * @format: Formatted
 * @list: List
 * @ind: in
 * @buffer: Buffer
 * @flgs: Calculates
 * @width: get
 * @presn: Presn
 * @size: Size
 * Return: 1 or 2;
 */

int hndlePrntFunc(const char *format, int *ind, va_list list, char buffer[],
				 int flgs, int width, int presn, int size)
{
	int i, prntd_chars = -1;
	format_t format_types[] = {
		{'c', prntChar}, {'s', prntStr}, {'%', prntPcnt}, {'i', prntInt},
		{'d', prntInt},	{'b', Pbin}, {'u', P_u_signed}, {'o', pOctal},
		{'x', pHexDecimal}, {'X', pHexUpper}, {'p', pPtr}, /* {'S', pNonPrnble}, */
		{'r', pRev}, {'R', pRot13Str}, {'\0', NULL}};
	for (i = 0; format_types[i].format != '\0'; i++)
		if (format[*ind] == format_types[i].format)
			return (format_types[i].funcn(list, buffer, flgs, width, presn, size));

	if (format_types[i].format == '\0')
	{
		prntd_chars = hndlePrntFuncDaf(format, ind, width);
	}
	return (prntd_chars);
}
