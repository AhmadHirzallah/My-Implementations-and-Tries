#include "../../include/ft_printf_utils.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"
void	ft_parse_flags(t_data *data_s)
{
	char	flag_chr;

	while ((ft_strchr(FLAGS, *data_s->str)))
	{
		flag_chr = *data_s->str;
		if ('0' == flag_chr)
			data_s->fmt_flags_s.is_zero_pad = true;
		else if ('+' == flag_chr)
			data_s->fmt_flags_s.plus = true;
		else if (' ' == flag_chr)
			data_s->fmt_flags_s.space = true;
		else if ('#' == flag_chr)
			data_s->fmt_flags_s.hashtag = true;
		else if ('-' == flag_chr)
			data_s->fmt_flags_s.left_justified = true;
		++data_s->str;
	}
}
