#include "../include/ft_printf.h"
#include "../include/libft.h"

void	ft_flush_buffer(t_data_s *data_s)
{
	data_s->rtrn_printf_value += write(1, data_s->printf_buffer,
			data_s->printf_buf_len);
	ft_bzero(data_s->printf_buffer, BUFFER_SIZE);
	data_s->printf_buf_len = 0;
}