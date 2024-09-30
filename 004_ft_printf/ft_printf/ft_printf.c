#include "../include/ft_printf.h"
#include "../include/libft.h"

static int	ft_init_data(t_data_s *data_s, const char *fmt)
{
	data_s->dynmc_nbr.int64 = 0;
	data_s->str = fmt;
	data_s->printf_buffer = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (NULL == data_s->printf_buffer)
		return (MALLOC_ERR);
	data_s->printf_buf_len = 0;
	data_s->rtrn_printf_value = 0;
	return (OK);
}

int	ft_printf(const char *fmt, ...)
{
	t_data_s	data_s;

	va_start(data_s.ap, fmt);
	if (MALLOC_ERR == ft_init_data(&data_s, fmt))
		return (PRINTF_ERR);
	while (*data_s.str)
	{
		if (*data_s.str == '%' && *(data_s.str++))
		{
			if (ft_parse_fmt(&data_s) == OK)
				ft_render_into_buffer();
			else
			{
				ft_flush_buffer();
				return (data_s.rtrn_printf_value);
			}
		}
		else
			ft_fill_buffer_chr();
		++data_s.str;
	}
	ft_flush_buffer(&data_s);
	va_end(data_s.ap);
	free(data_s.printf_buffer);
	return (data_s.rtrn_printf_value);
}