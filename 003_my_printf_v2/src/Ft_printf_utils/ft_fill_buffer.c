#include "../../include/ft_printf.h"
#include "../../include/ft_printf_utils.h"
#include "../../include/libft.h"

void	ft_fill_buffer(t_data *data_s, char c)
{
	if (data_s->buf_index == BUFFER_SIZE)
	{
		// refresh index and write str in stdout
		ft_flush_buffer(data_s);
	}
	else
	{
		data_s->buf[data_s->buf_index++] = c;
	}
}
