#include "ft_printf_utils.h"
#include "../Libft/libft.h"
#include "../ft_printf.h"
#include <stdbool.h>
#include <stdarg.h>

void	ft_putstr_buf_n(char *str, int precision, t_data *data_s)
{
	if (precision <= 0)
		return ;
	while (precision-- && *str)
		ft_fill_buffer(data_s, *str++);
}