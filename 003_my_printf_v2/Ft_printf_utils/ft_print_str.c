
#include "ft_printf_utils.h"
#include "../Libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>		// write
#include <stdbool.h>
#include <stdarg.h>

void	ft_print_str(t_data *data_s, char *str)
{
	if (NULL == str)
		str = "(null)";
	ft_set_str_pad_spaces(data_s, str);
	if (data_s->fmt_flags_s.left_justified)
	{
		if (data_s->fmt_flags_s.precision_val >= 0)
			ft_putstr_buf_n(str, data_s->fmt_flags_s.precision_val, data_s);
		else
			ft_putstr_buf_n(str, ft_strlen(str), data_s);	
		ft_pad_buf_wth_n_chrs(' ', data_s->fmt_flags_s.padding_spaces, data_s);
	}
	else
	{
		ft_pad_buf_wth_n_chrs(' ', data_s->fmt_flags_s.padding_spaces, data_s);
		if (data_s->fmt_flags_s.precision_val >= 0)
			ft_putstr_buf_n(str, data_s->fmt_flags_s.precision_val, data_s);
		else
			ft_putstr_buf_n(str, ft_strlen(str), data_s);	
	}
}
