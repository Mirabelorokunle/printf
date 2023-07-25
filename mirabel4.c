#include "main.h"

/**
 * pNonPrnbleDaf - Prints
 * @i: List
 * @str: Buffer
 * @offset: Calculates
 * @buffer: get
 * Return: Number
 */
void pNonPrnbleDaf(int i, char *str, int offset, char buffer[])
{
	if (isPrntble(str[i]))
		buffer[i + offset] = str[i];
	else
		offset += appndHexCode(str[i], buffer, i + offset);
}
/* DONE 12 .......................... END ........................12..*/


/* DONE 11 .......................... START ........................11..*/
/**
 * pRev - Prints
 * @types: List
 * @buffer: Buffer
 * @flgs: Calculates
 * @width: get
 * @presn: Presn
 * @size: Size
 * Return: Numbers
 */

int pRev(va_list types, char buffer[],
				  int flgs, int width, int presn, int size)
{
	char *str;
	int i, cnt = 0;

	NOT_USED(buffer), NOT_USED(flgs), NOT_USED(width), NOT_USED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		NOT_USED(presn);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		writeFuncDaf(z);
		cnt++;
	}
	return (cnt);
}
/* DONE 11 .......................... END ........................11..*/



/* DONE XX .......................... WRITE .............................XX..*/
/**
 * writeFuncDaf - Prints
 * @cha: List
 */
void writeFuncDaf(char cha)
{
	write(1, &cha, 1);
}
/* DONE XX .......................... WRITE .............................XX..*/





/* DONE 10 .......................... START ........................10..*/

/**
 * pRot13Str - Print
 * @types: List
 * @buffer: Buffe
 * @flgs: Calculates
 * @width: get
 * @presn: Presn
 * @size: Size
 * Return: Number
 */
int pRot13Str(va_list types, char buffer[],
					  int flgs, int width, int presn, int size)
{
	char x, *str, chk;
	unsigned int i, j;
	int cnt = 0;
	char in[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char out[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	x = 'a';
	str = va_arg(types, char *);
	NOT_USED(buffer), NOT_USED(flgs), NOT_USED(width), NOT_USED(presn);
	NOT_USED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				chk = 1;
				pRot13StrDaf(x, i, j, out, str, chk);
				cnt++;
				break;
			}
		}
		if (!in[j])
		{
			chk = 2;
			pRot13StrDaf(x, i, j, out, str, chk);
			cnt++;
		}
	}
	return (cnt);
}

/**
 * pRot13StrDaf - Print
 * @x: List
 * @i: Buffe
 * @j: Calculates
 * @sout: get
 * @sstr: get
 * @chk: chk
 * Return: Number
 */
void pRot13StrDaf(char x, int i, int j, char *sout, char *sstr, int chk)
{
	if (chk == 1)
		x = sout[j];
	else
		x = sstr[i];
	write(1, &x, 1);

}
