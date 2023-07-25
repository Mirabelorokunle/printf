#include "main.h"

/**
 * pHexDecimal - Prints
 * @types: List
 * @buffer: Buffer
 * @flgs: Calculates
 * @width: get
 * @presn: Presn
 * @size: Size
 * Return: Number
 */
int pHexDecimal(va_list types, char buffer[],
					int flgs, int width, int presn, int size)
{
	int res;

	res = pHex(types, "0123456789abcdef", buffer, flgs, 'x', width, presn, size);
	return (res);
}


/**
 * pHexUpper - Prints
 * @types: List
 * @buffer: Buffer
 * @flgs: Calculates
 * @width: get
 * @presn: Presn
 * @size: Size
 * Return: Number
 */
int pHexUpper(va_list types, char buffer[],
					int flgs, int width, int presn, int size)
{
	int res;

	res = pHex(types, "0123456789ABCDEF", buffer, flgs, 'X', width, presn, size);
	return (res);
}

/**
 * pHex - Prints
 * @types: Lis
 * @map_to: Array
 * @buffer: Buffer
 * @flgs: Calculates
 * @flag_ch: Calculates
 * @width: get
 * @presn: Presn
 * @size: Size
 * @size: Size
 * Return: Number
 */
int pHex(va_list types, char map_to[], char buffer[],
			int flgs, char flag_ch, int width, int presn, int size)
{
	int n = BUFFER_SIZE - 2, res;
	unsigned long int num = va_arg(types, unsigned long int), init_num = num;

	NOT_USED(width);

	num = cSizeUsignd(num, size);

	if (num == 0)
		buffer[n--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[n--] = map_to[num % 16];
		num /= 16;
	}

	if (flgs & HASH && init_num != 0)
	{
		buffer[n--] = flag_ch;
		buffer[n--] = '0';
	}

	n++;

	res = wrteUnsgnd(0, n, buffer, flgs, width, presn, size);
	return (res);
}


/**
 * pPtr - Prints
 * @types: List
 * @buffer: Buffer
 * @flgs: Calculates
 * @width: get
 * @presn: Presn
 * @size: Size
 * Return: Number
 */
int pPtr(va_list types, char buffer[],
				int flgs, int width, int presn, int size)
{
	char extra_c = 0, padd = ' ', map_to[] = "0123456789abcdef";
	int ind = BUFFER_SIZE - 2, len = 2, padd_start = 1, res; /* len=2, for '0x' */
	unsigned long num_addrs;
	void *addrs = va_arg(types, void *);

	NOT_USED(width), NOT_USED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';
	NOT_USED(presn);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		len++;
	}

	if ((flgs & ZERO) && !(flgs & MINUS))
		padd = '0';
	if (flgs & PLUS)
		extra_c = '+', len++;
	else if (flgs & SPACE)
		extra_c = ' ', len++;

	ind++;

	/*return (write(1, &buffer[i], BUFFER_SIZE - i - 1));*/
	res = wrtePtr(buffer, ind, len, width, flgs, padd, extra_c, padd_start);
	return (res);
}

