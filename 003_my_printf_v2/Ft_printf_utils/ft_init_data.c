#include "ft_printf_utils.h"
#include "../Libft/libft.h"
#include "../ft_printf.h"
#include <stdbool.h>
#include <stdarg.h>

int	ft_init_data(t_data *data_s, const char *fmt)
{
	data_s->written_chrs_count = 0;
	data_s->str = fmt;
	data_s->buf = (char *)ft_calloc(BUFFER_SIZE , sizeof(char));
	if (NULL == data_s->buf)
		return (MALLOC_ERR);
	data_s->buf_index = 0;
	return (OK);
}