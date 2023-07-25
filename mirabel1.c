#include "main.h"

/**
 * _printf - function
 * @format: format
 * Return: prntd
 */
int _printf(const char *format, ...)
{
	int i, prntd = 0, prntd_chars = 0, flgs, width, presn, size, buff_ind_num = 0;

	va_list list;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind_num++] = format[i];
			if (buff_ind_num == BUFFER_SIZE)
				prntBuf(buffer, &buff_ind_num);
			/* write(1, &format[i], 1);*/
			prntd_chars++;
		}
		else
		{
			prntBuf(buffer, &buff_ind_num);
			flgs = getFlgsFunc(format, &i);
			width = getWidthFunc(format, &i, list);
			presn = getPresnFunc(format, &i, list);
			size = getSizeFunc(format, &i);
			++i;
			prntd = hndlePrntFunc(format, &i, list, buffer,
								 flgs, width, presn, size);
			if (prntd == -1)
				return (-1);
			prntd_chars += prntd;
		}
	}
	prntBuf(buffer, &buff_ind_num);
	va_end(list);
	return (prntd_chars);
}


/**
 * prntBuf - Prints
 * @buffer: Array
 * @buff_ind_num: Index
 */
void prntBuf(char buffer[], int *buff_ind_num)
{
	if (*buff_ind_num > 0)
		write(1, &buffer[0], *buff_ind_num);

	*buff_ind_num = 0;
}


/**
 * prntChar - Prints
 * @types: List
 * @buffer: Buffer
 * @flgs: Calculates
 * @width: Width
 * @presn: Presn
 * @size: Size
 * Return: Number
 */
int prntChar(va_list types, char buffer[],
			   int flgs, int width, int presn, int size)
{
	int resu;

	char c = va_arg(types, int);

	resu = hWriteChar(c, buffer, flgs, width, presn, size);

	return (resu);
}


/* DONE 14 .......................... START ........................14..*/
/**
 * prntStr - Prints
 * @types: List
 * @buffer: Buffer
 * @flgs: Calculates
 * @width: get width.
 * @presn: Presn
 * @size: Size
 * Return: Number
 */
int prntStr(va_list types, char buffer[],
			 int flgs, int width, int presn, int size)
{
	int len = 0, chk, res, resWidth;
	char *str = va_arg(types, char *);

	NOT_USED(buffer), NOT_USED(flgs), NOT_USED(width);
	NOT_USED(presn), NOT_USED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (presn >= 6)
			str = " ";
	}

	while (str[len] != '\0')
		len++;

	if (presn >= 0 && presn < len)
		len = presn;

	if (width > len)
	{
		if (!(flgs & MINUS))
		{
			chk = 1;
			resWidth = prntStrDaf(width, chk, len, str);
			return (resWidth);
		}
		else
		{
			chk = 2;
			resWidth = prntStrDaf(width, chk, len, str);
			return (resWidth);
		}
	}
	res = write(1, str, len);
	return (res);
}

/**
 * prntStrDaf - Prints
 * @width: get width.
 * @chk: Presn
 * @len: Size
 * @str: Size
 * Return: Number
 */
int prntStrDaf(int width, int chk, int len, char *str)
{
	int i;

	if (chk == 2)
	{
		for (i = width - len; i > 0; i--)
			write(1, " ", 1);
		write(1, &str[0], len);
	}

	else
	{
		write(1, &str[0], len);
		for (i = width - len; i > 0; i--)
			write(1, " ", 1);
	}

	return (width);
}
