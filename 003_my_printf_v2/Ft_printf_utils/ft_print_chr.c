
#include "ft_printf_utils.h"
#include "../Libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>		// write
#include <stdbool.h>
#include <stdarg.h>

void	ft_print_chr(t_data *data_s, int c)
{
	int	width;

	width = data_s->fmt_flags_s.width_val;
	if (width > 1)
	{
		if (data_s->fmt_flags_s.left_justified)
		{
			ft_pad_buf_wth_n_chrs((char)c, 1, data_s);
			ft_pad_buf_wth_n_chrs(' ', width - 1, data_s);
		}
		else
		{
			ft_pad_buf_wth_n_chrs(' ', width - 1, data_s);
			ft_pad_buf_wth_n_chrs((char)c, 1, data_s);
		}
	}
	else
		ft_pad_buf_wth_n_chrs((char)c, 1, data_s);
}	