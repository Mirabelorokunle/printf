#include "main.h"

/* DONE 14 .......................... END ........................14..*/

/**
 * prntPcnt - Prints
 * @types: Lists
 * @buffer: Buffer
 * @flgs: Calculates
 * @width: get
 * @presn: Presn
 * @size: Size
 * Return: Number
 */
int prntPcnt(va_list types, char buffer[],
				int flgs, int width, int presn, int size)
{
	int res;

	NOT_USED(types), NOT_USED(buffer), NOT_USED(flgs), NOT_USED(width);
	NOT_USED(presn), NOT_USED(size);

	res = write(1, "%%", 1);

	return (res);
}

/**
 * prntInt - Print
 * @types: Lists
 * @buffer: Buffer
 * @flgs: Calculates
 * @width: get
 * @presn: Presn
 * @size: Size
 * Return: Number
 */
int prntInt(va_list types, char buffer[],
			int flgs, int width, int presn, int size)
{
	int i = BUFFER_SIZE - 2, iNeg = 0, res;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convtSizeNum(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		iNeg = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	res = writeNum(iNeg, i, buffer, flgs, width, presn, size);
	return (res);
}


/* DONE 13 .......................... START ........................13..*/
/**
 * Pbin - Prints
 * @types: Lists
 * @buffer: Buffer
 * @flgs: Calculates
 * @width: get
 * @presn: Presn
 * @size: Size
 * Return: Numbers
 */
int Pbin(va_list types, char buffer[],
				int flgs, int width, int presn, int size)
{
	unsigned int n, m, i, sum, a[32];
	int cnt;

	NOT_USED(buffer), NOT_USED(flgs), NOT_USED(width), NOT_USED(presn);
	NOT_USED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, cnt = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			writeFuncDaf(z);
			cnt++;
		}
	}
	return (cnt);
}

/* DONE 13 .......................... END ........................13..*/

/**
 * P_u_signed - Prints
 * @types: List
 * @buffer: Buffer
 * @flgs: Calculates
 * @width: get
 * @presn: Presn
 * @size: Size
 * Return: Number
 */
int P_u_signed(va_list types, char buffer[],
				int flgs, int width, int presn, int size)
{
	int n = BUFFER_SIZE - 2, res;
	unsigned long int num = va_arg(types, unsigned long int);

	num = cSizeUsignd(num, size);

	if (num == 0)
		buffer[n--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[n--] = (num % 10) + '0';
		num /= 10;
	}

	n++;
	res = wrteUnsgnd(0, n, buffer, flgs, width, presn, size);
	return (res);
}

/**
 * pOctal - Prints
 * @types: List
 * @buffer: Buffer
 * @flgs: Calculate
 * @width: get
 * @presn: Presn
 * @size: Size
 * Return: Number
 */
int pOctal(va_list types, char buffer[],
			int flgs, int width, int presn, int size)
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
		buffer[n--] = (num % 8) + '0';
		num /= 8;
	}

	if (flgs & HASH && init_num != 0)
		buffer[n--] = '0';

	n++;
	res = wrteUnsgnd(0, n, buffer, flgs, width, presn, size);
	return (res);
}
