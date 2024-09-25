
#include "ft_printf_utils.h"
#include "../Libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>		// write
#include <stdbool.h>
#include <stdarg.h>

void	ft_set_str_pad_spaces(t_data *data_s, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (data_s->fmt_flags_s.width_val > 0)
	{
		if (data_s->fmt_flags_s.precision_val >= 0)
		{	
			if (data_s->fmt_flags_s.precision_val >= len)
			{
				data_s->fmt_flags_s.padding_spaces = data_s->fmt_flags_s.width_val -\
													len;
			}
			else if (data_s->fmt_flags_s.precision_val < len)
			{
				//		to handle ahmad with 10 width with 3 perc will be 10 - 3 print "        ahm"
				data_s->fmt_flags_s.padding_spaces = data_s->fmt_flags_s.width_val -\
												data_s->fmt_flags_s.precision_val;
			}
		}
		else
		{
			data_s->fmt_flags_s.padding_spaces = data_s->fmt_flags_s.width_val -\
												len;
		}
	}
}