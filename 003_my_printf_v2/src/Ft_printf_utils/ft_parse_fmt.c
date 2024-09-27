#include "../../include/ft_printf_utils.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"

int	ft_parse_fmt(t_data *data_s)
{
	ft_bzero(&data_s->fmt_flags_s, sizeof(t_fmt_flags));
	ft_bzero(data_s->tmp_nbrs_bfr, sizeof(data_s->tmp_nbrs_bfr));
	data_s->tmp_nbrs_bfr_index = 0;
	data_s->fmt_flags_s.precision_val = -1;	// Because we will consider (.0) as a case so we check if precision is major  or equal than 0; Not the width; (WIDTH CANT == 0) but precision can.
	ft_parse_flags(data_s);
	// For width:
	ft_extract_val(data_s, &data_s->fmt_flags_s.width_val);
	//For Precision:
	if (*data_s->str == '.' && *(++data_s->str))
		ft_extract_val(data_s, &data_s->fmt_flags_s.precision_val);
	if (!ft_strchr(SPECIFIERS, (int)*data_s->str))
		return (PARSE_ERR);
	else
	{
		data_s->fmt_flags_s.specifier = (char)*data_s->str;
		if (ft_strchr("diu", (int)data_s->fmt_flags_s.specifier))
			data_s->fmt_flags_s.base_e = BASE_10;
		else if (ft_strchr("xXp", (int)data_s->fmt_flags_s.specifier))
		{
				data_s->fmt_flags_s.base_e = BASE_16;
				if ('X' == data_s->fmt_flags_s.specifier)
					data_s->fmt_flags_s.upper_case = true;
		}
	}
	return (OK);
	/*ft_parse_width(data_s);
	ft_parse_precision(data_s);*/
	
}
