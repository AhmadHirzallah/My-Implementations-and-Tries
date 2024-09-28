#include "../../include/ft_printf.h"
#include "../../include/ft_printf_utils.h"
#include "../../include/libft.h"

void	ft_flush_buffer(t_data *data_s)
{
	data_s->written_chrs_count += write(STDOUT_FILENO, data_s->buf,
			data_s->buf_index);
	ft_bzero(data_s->buf, BUFFER_SIZE);
	data_s->buf_index = 0;
}
