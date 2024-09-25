#include "ft_printf_utils.h"
#include "../Libft/libft.h"
#include "../ft_printf.h"
#include <stdbool.h>
#include <stdarg.h>

void	ft_render_fmt(t_data *data_s)
{
	char	specifier_chr;

	specifier_chr = data_s->fmt_flags_s.specifier;
	if ('%' == specifier_chr)
		ft_print_chr(data_s, '%');
	else if ('c' == specifier_chr)
		ft_print_chr(data_s , (char)va_arg(data_s->ap, int));
	else if ('s' == specifier_chr)
		ft_print_str(data_s, va_arg(data_s->ap, char *));

}
