#include "ft_printf.h"

int	count_digits(int num)
{
	int	digits;

	if (num == 0)
		return (1);
	if (num < 0)
		num *= -1;
	digits = 0;
	while (num != 0)
	{
		digits++;
		num /= 10;
	}
	return (digits);
}

int	loop_print(int *format_num, char c)
{
	int	printed;

	printed = 0;
	while (*format_num > 0)
	{
		ft_putchar_fd(c, 1);
		*format_num -= 1;
		printed++;
	}
	return (printed);
}