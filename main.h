#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define NOT_USED(x) (void)(x)
#define BUFFER_SIZE 1024

#define MINUS 1
#define PLUS 2
#define ZERO 4
#define HASH 8
#define SPACE 16

#define LONG 2
#define SHORT 1

/**
 * struct format - Struct op
 *
 * @format: The format.
 * @funcn: The function associated.
 */
struct format
{
	char format;
	int (*funcn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct format format_t - Struct op
 *
 * @format: The format.
 * @funcn_t: The function associated.
 */
typedef struct format format_t;

int _printf(const char *format, ...);
int hndlePrntFunc(const char *format, int *i,
va_list list, char buffer[], int flags, int width,
				int precision, int size);
int prntChar(va_list types, char buffer[], int flags,
				int width, int precision, int size);
int prntStr(va_list types, char buffer[], int flags,
				int width, int precision, int size);
int prntPcnt(va_list types, char buffer[], int flags,
				int width, int precision, int size);
int prntInt(va_list types, char buffer[], int flags,
				int width, int precision, int size);
int Pbin(va_list types, char buffer[], int flags,
				int width, int precision, int size);
int P_u_signed(va_list types, char buffer[], int flags,
				int width, int precision, int size);
int pOctal(va_list types, char buffer[], int flags,
				int width, int precision, int size);
int pHexDecimal(va_list types, char buffer[], int flags,
				int width, int precision, int size);
int pHexUpper(va_list types, char buffer[], int flags,
				int width, int precision, int size);
int pHex(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width,
				int precision, int size);
int pNonPrnble(va_list types, char buffer[], int flags,
				int width, int precision, int size);
int pPtr(va_list types, char buffer[], int flags, int width,
				int precision, int size);
int getWidthFunc(const char *format, int *i, va_list list);
int getFlgsFunc(const char *format, int *i);
int getSizeFunc(const char *format, int *i);
int getPresnFunc(const char *format, int *i, va_list list);
int pRev(va_list types, char buffer[], int flags, int width,
				int precision, int size);
int pRot13Str(va_list types, char buffer[], int flags,
				int width, int precision, int size);
int hWriteChar(char c, char buffer[], int flags, int width,
				int precision, int size);
int writeNum(int is_positive, int ind, char buffer[], int flags,
				int width, int precision, int size);
int wrteNum(int ind, char buffer[], int flgs, int width,
				int prec, int len, char padd, char extra_c);
int wrtePtr(char buffer[], int ind, int len, int width,
				int flgs, char padd, char extra_c, int padd_start);
int wrteUnsgnd(int iNeg, int ind, char buffer[], int flgs,
				int width, int presn, int size);
int isPrntble(char c);
int appndHexCode(char ascii_code, char buffer[], int i);
int isDigit(char c);
long int convtSizeNum(long int num, int size);
long int cSizeUsignd(unsigned long int num, int size);
void prntBuf(char buffer[], int *buff_ind_num);

void writeFuncDaf(char cha);

int bufffuncDaf(char buffer[], int ind, char extra_c, int i,
				int len, int chk);
int bufffuncDaf2(char buffer[], int ind, char extra_c, int i,
				int len, int padd_start);
int wrteUnsgndDaf(int ind, char buffer[], int flgs, int width,
				char padd, int len);
int wrteNumDaf(int ind, char buffer[], int flgs, int width,
				int len, char padd, char extra_c);
int hWriteCharDaf(char buffer[], int flgs, int width, char padd);
int hndlePrntFuncDaf(const char *format, int *ind, int width);
void getWidthFuncDaf(const char *format, va_list list, int chk);
void getPresnFuncDaf(const char *format, int *i, va_list list,
				int chk);
void pRot13StrDaf(char x, int i, int j, char *sout, char *sstr,
				int chk);
void pNonPrnbleDaf(int i, char *str, int offset, char buffer[]);
int prntStrDaf(int width, int chk, int len, char *str);


#endif
