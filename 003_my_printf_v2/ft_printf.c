#include "ft_printf.h"
#include "Libft/libft.h"
#include "Ft_printf_utils/ft_printf_utils.h"

int	ft_printf(const char *fmt, ...)
{
	t_data	data_s;

	va_start(data_s.ap, fmt);
	if (ft_init_data(&data_s, fmt))
		return (-1);
	while (*data_s.str)
	{
		if (*data_s.str == '%' && *(++data_s.str))
		{
			if (ft_parse_fmt(&data_s) == PARSE_ERR)
			{
				ft_flush_buffer(&data_s);
				return (data_s.written_chrs_count);
			}
			ft_render_fmt(&data_s);
		}
		else
			ft_fill_buffer(&data_s, (char)*data_s.str);
		++data_s.str;
	}
	ft_flush_buffer(&data_s);
	va_end(data_s.ap);
	free(data_s.buf); 
	return (data_s.written_chrs_count);
}