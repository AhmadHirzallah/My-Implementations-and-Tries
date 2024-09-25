#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_print_chr(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		ft_print_chr((int)(*str));
		++len;
		++str;
	}
	return (len);
}


int	ft_print_nbr(long l_nbr, int base)
{
	int			count;
	char	*hex_symbols;

	hex_symbols = "0123456789abcdef";
	count = 0;
	if (l_nbr < 0)
	{
		write(1, "-", 1);
		return (ft_print_nbr(-l_nbr, base) + 1);
	}
	else if (l_nbr < base)
	{
		return (ft_print_chr((int)hex_symbols[l_nbr]));
	}
	else
	{
		count += ft_print_nbr(l_nbr / base, base);
		return (count + ft_print_nbr((l_nbr % base), base));

	}
}


int	ft_print_spfc_fmt(char specifier_chr, va_list ap)
{
	int	printf_value;

	printf_value = 0;
	if (specifier_chr == 'c')
		printf_value += ft_print_chr(va_arg(ap, int));		//char is 1 byte integer
	else if (specifier_chr == 's')
		printf_value += ft_print_str(va_arg(ap, char *));
	else if (specifier_chr == 'd')
		printf_value += ft_print_nbr((long)(va_arg(ap,int)), 10);
	else if (specifier_chr == 'x')
		printf_value += ft_print_nbr((long)(va_arg(ap, unsigned int)), 16);
	else
		printf_value += write(1, &specifier_chr, 1);
	return (printf_value);
}

int	ft_printf(const char *format, ...)
{
			//Argument Pointer
	va_list	ap;		
	int			printf_value;

	va_start(ap, format);
	printf_value = 0;
	while (*format)
	{
		if (*format == '%')
			printf_value += ft_print_spfc_fmt(*++format, ap);
		else
			printf_value += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (printf_value);
}


int	main()
{
	int	printf_value;

	printf_value = 0;
	printf_value += ft_printf("Hello %s, Today is %d, in hex %x, char: %c\n", "Johan", 27,27,'z');
	ft_printf("\nThe chars written are %d\n\n\n\n", printf_value);
	
	
	printf_value = 0;
	printf_value += printf("Hello %s, Today is %d, in hex %x, char: %c\n", "Johan", 27,27,'z');
	ft_printf("\nThe chars written are %d\n", printf_value);











	// printf_value = 0;
	// printf_value += ft_printf("%d", -2147483648);
	// ft_printf("\nThe chars written are %d\n", printf_value);



	// printf_value = 0;
	// printf_value += printf("%d", -2147483648);
	// printf("\nThe chars written are %d\n", printf_value);
	return (0);
}
 



	//printf_value = ft_printf("%x\n", 42);
	//printf_value += printf("%x", __INT32_MAX__);
	//ft_printf("The chars written are %d\n", printf_value);