
#include "ft_printf_utils.h"
#include "../Libft/libft.h"
#include "ft_printf.h"
#include <stdbool.h>
#include <stdarg.h>

void	ft_render_fmt(t_data *data_s)
{
	if ('%' == data_s->fmt_flags_s.specifier)
		ft_print_chr(data_s, '%');
	else if ('c' == data_s->fmt_flags_s.specifier)
		ft_print_chr(data_s , (char)va_arg(data_s->ap, int));
	else if ('s' == data_s->fmt_flags_s.specifier)
		ft_print_str(data_s, va_arg(data_s->ap, char *));
	else if (ft_strchr("diupxX", data_s->fmt_flags_s.specifier))//*data_s->str
	{
		if (ft_strchr("di", data_s->fmt_flags_s.specifier))
		{
			data_s->dynmic_nbr_vals.int64 = (long) va_arg(data_s->ap, int);
			data_s->fmt_flags_s.is_signed_nbr = true;
			if (data_s->dynmic_nbr_vals.int64 < 0)
				data_s->fmt_flags_s.is_negative_nbr = true;

		}
		else if ('p' == data_s->fmt_flags_s.specifier)
			data_s->dynmic_nbr_vals.uint64 = (unsigned long) va_arg(data_s->ap, unsigned long);
		//else if ("xXu", )
		ft_print_nbrs();
	}

}
