#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
/**
*_printf - function
*@format: var
*Return: value
*/
int _printf(const char *format, ...)
{
	unsigned int len = 0;
	unsigned int i = 0;
	va_list arguat;
	unsigned int formsize = 0;
	char temp[100000] = "\0";

	va_start(arguat, format);
	if (format[0] == '\0')
		return (-1);
	while (*(format + formsize) != '\0')
	{
		if (*(format + formsize) == '%' &&
				(*(format + formsize + 1) == 's' || *(format + formsize + 1) == 'c'))
		{
			strcpy(temp, va_arg(arguat, char*));
			while (*(temp + i) != '\0')
			{
				_putchar(*(temp + i));
				i++;
			}
			len += i;
			i = 0;
			formsize++;
		}
		else
		{
			_putchar(*(format + formsize));
			len++;
		}
		formsize++;
	}
	return (len);
}
