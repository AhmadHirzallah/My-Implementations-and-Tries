#include "../../include/ft_printf.h"
#include "../../include/ft_printf_utils.h"
#include "../../include/libft.h"
#include <stdbool.h>

static bool	ft_set_zeros_wth_precis(t_data *data_s)
{
	if ((data_s->fmt_flags_s.precision_val >= 0)
		&& (data_s->fmt_flags_s.precision_val) > (data_s->tmp_nbrs_bfr_index))
	{
		data_s->fmt_flags_s.padding_zeros = (data_s->fmt_flags_s.precision_val)
			- (data_s->tmp_nbrs_bfr_index);
		return (true);
	}
	return (false);
}

static void	ft_set_width_wth_nbr_len(t_data *data_s)
{
	if (data_s->fmt_flags_s.width_val > data_s->tmp_nbrs_bfr_index)
		data_s->fmt_flags_s.padding_zeros = data_s->fmt_flags_s.width_val
			- data_s->tmp_nbrs_bfr_index;
}

static void	ft_set_hash_modific(t_data *data_s)
{
	if (ft_strchr("xX", data_s->fmt_flags_s.specifier)
		&& (data_s->fmt_flags_s.hashtag) && (data_s->tmp_nbrs_bfr[0] != '0'))
		data_s->fmt_flags_s.padding_zeros -= 2;
	/*else if (data_s->fmt_flags_s.specifier == 'p')
		data_s->fmt_flags_s.padding_zeros -= 2;	*/ // No padding zeros for `%p`.
}

static void	ft_set_plus_space(t_data *data_s)
{
	if ((data_s->fmt_flags_s.plus) || (data_s->fmt_flags_s.space))
		data_s->fmt_flags_s.padding_zeros--;
}

void	ft_pad_nbr_wth_zeros(t_data *data_s)
{
	if (ft_set_zeros_wth_precis(data_s))
		return ;
	if (data_s->fmt_flags_s.is_zero_pad)
	{
		if ((data_s->fmt_flags_s.left_justified)
			|| (data_s->fmt_flags_s.specifier == 'u'))
			return ;
		ft_set_width_wth_nbr_len(data_s);
		ft_set_hash_modific(data_s);
		ft_set_plus_space(data_s);
		if (data_s->fmt_flags_s.padding_zeros < 0)
			data_s->fmt_flags_s.padding_spaces = 0;
	}
}