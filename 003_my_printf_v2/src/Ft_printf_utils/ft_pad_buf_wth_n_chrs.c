#include "../../include/ft_printf_utils.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"
void	ft_pad_buf_wth_n_chrs(char c, int precision, t_data *data_s)
{
	if (precision <= 0)
		return ;
	while (precision--)
		ft_fill_buffer(data_s, c);
}
