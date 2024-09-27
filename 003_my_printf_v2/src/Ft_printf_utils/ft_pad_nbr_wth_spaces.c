
#include "../../include/ft_printf_utils.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"
#include <stdbool.h>

static bool	ft_set_hash_modific(t_data *data_s)
{
	if (ft_strchr("xXp", data_s->fmt_flags_s.specifier)
				&& (data_s->fmt_flags_s.hashtag)
				&&  (data_s->tmp_nbrs_bfr[0] != '0'))
	{
		data_s->fmt_flags_s.padding_spaces -= 2;
		return (true);
	}
	if ('u' == data_s->fmt_flags_s.specifier)
		return (true);
	return (false);
}

static bool	ft_set_plus_space_neg(t_data *data_s)
{
	if (CONVERTED_FROM_NEG == (data_s->fmt_flags_s.neg_nbr_track))
	{
		data_s->fmt_flags_s.padding_spaces--;
		return (true);

	}
	else if (AS_NULL_NOT_NEG == (data_s->fmt_flags_s.neg_nbr_track)
				&& data_s->fmt_flags_s.plus)
	{
		data_s->fmt_flags_s.padding_spaces--;
		return (true);
	}
	else if (AS_NULL_NOT_NEG == (data_s->fmt_flags_s.neg_nbr_track)
				&& data_s->fmt_flags_s.space)
	{
		data_s->fmt_flags_s.padding_spaces--;
		return (true);
	}
	return (false);

}

void	ft_pad_nbr_wth_spaces(t_data *data_s)
{// [% 10.5, "123"] -->  "     00123"
	data_s->fmt_flags_s.padding_spaces = data_s->fmt_flags_s.width_val - \
										((data_s->tmp_nbrs_bfr_index) + (data_s->fmt_flags_s.padding_zeros));
	if (ft_set_hash_modific(data_s))
		return ;
	if (ft_set_plus_space_neg(data_s))
		return ;
	
}