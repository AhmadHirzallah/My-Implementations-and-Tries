#include "../../include/ft_printf_utils.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"

void	ft_render_fmt(t_data *data_s)
{
	if ('%' == data_s->fmt_flags_s.specifier)
		ft_print_chr(data_s, '%');
	else if ('c' == data_s->fmt_flags_s.specifier)
		ft_print_chr(data_s , (char)va_arg(data_s->ap, int));
	else if ('s' == data_s->fmt_flags_s.specifier)
		ft_print_str(data_s, va_arg(data_s->ap, char *));
	else if (ft_strchr("di", data_s->fmt_flags_s.specifier))
	{
		data_s->dynmic_nbr_vals.int64 = (long) va_arg(data_s->ap, int);
		data_s->fmt_flags_s.is_signed_nbr = true;
		if (data_s->dynmic_nbr_vals.int64 < 0)
			data_s->fmt_flags_s.neg_nbr_track = NEG_NBR;
		ft_print_nbrs(data_s);
	}
	else if ('p' == data_s->fmt_flags_s.specifier)
	{
		data_s->dynmic_nbr_vals.uint64 = (unsigned long)va_arg(data_s->ap, unsigned long);
		ft_print_nbrs(data_s);
	}
	else if (ft_strchr("xXu", data_s->fmt_flags_s.specifier))
	{
		data_s->dynmic_nbr_vals.uint64 = (unsigned long)va_arg(data_s->ap, unsigned int);
		ft_print_nbrs(data_s);
	}
	// Magical Print Numbers to all types:


}
