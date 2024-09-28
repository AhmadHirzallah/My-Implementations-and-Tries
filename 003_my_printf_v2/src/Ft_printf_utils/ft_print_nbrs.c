#include "../../include/ft_printf.h"
#include "../../include/ft_printf_utils.h"
#include "../../include/libft.h"

static void	ft_put_0x(t_data *data_s)
{
	if (ft_strchr("xX", data_s->fmt_flags_s.specifier)
		&& (data_s->fmt_flags_s.hashtag) && (data_s->tmp_nbrs_bfr[0] != '0'))
	{
		if (data_s->fmt_flags_s.upper_case)
			ft_putstr_buf_n("0X", 2, data_s);
		else
			ft_putstr_buf_n("0x", 2, data_s);
		data_s->fmt_flags_s.padding_spaces -= 2;
	}
	else if ('p' == data_s->fmt_flags_s.specifier)
	{
		ft_putstr_buf_n("0x", 2, data_s);
	}
}

static void	ft_put_sign_symb_hash(t_data *data_s)
{
	if (data_s->fmt_flags_s.is_signed_nbr)
	{
		if (data_s->fmt_flags_s.neg_nbr_track == CONVERTED_FROM_NEG)
			ft_pad_buf_wth_n_chrs('-', 1, data_s);
		else if ((data_s->fmt_flags_s.neg_nbr_track == AS_NULL_NOT_NEG)
			&& (data_s->fmt_flags_s.plus))
			ft_pad_buf_wth_n_chrs('+', 1, data_s);
		else if ((data_s->fmt_flags_s.space) && !(data_s->fmt_flags_s.plus))
			ft_pad_buf_wth_n_chrs(' ', 1, data_s);
	}
}

void	ft_print_nbrs(t_data *data_s)
{
	if (data_s->dynmic_nbr_vals.uint64 == 0
		&& data_s->fmt_flags_s.specifier == 'p')
	{
		ft_putstr_buf_n("(nil)", 5, data_s);
		return ;
	}
	// 1992
	ft_itoa_base_bfr(data_s, data_s->dynmic_nbr_vals);

	// check padding spaces and zeros
	ft_pad_nbr_wth_zeros(data_s);
	ft_pad_nbr_wth_spaces(data_s);

	// write nbr in buffer
	if (data_s->fmt_flags_s.left_justified)
	{
		if ('p' == data_s->fmt_flags_s.specifier)
			data_s->fmt_flags_s.padding_spaces -= 2;
		if (data_s->fmt_flags_s.base_e == BASE_16)
			ft_put_0x(data_s);
		ft_put_sign_symb_hash(data_s);
		ft_pad_buf_wth_n_chrs('0', data_s->fmt_flags_s.padding_zeros, data_s);
		ft_putstr_buf_n(data_s->tmp_nbrs_bfr, data_s->tmp_nbrs_bfr_index,
			data_s);
		ft_pad_buf_wth_n_chrs(' ', data_s->fmt_flags_s.padding_spaces, data_s);
	}
	else
	{
		if ('p' == data_s->fmt_flags_s.specifier)
			data_s->fmt_flags_s.padding_spaces -= 2;
		ft_pad_buf_wth_n_chrs(' ', data_s->fmt_flags_s.padding_spaces, data_s);
		if (data_s->fmt_flags_s.base_e == BASE_16)
			ft_put_0x(data_s);
		ft_put_sign_symb_hash(data_s);
		ft_pad_buf_wth_n_chrs('0', data_s->fmt_flags_s.padding_zeros, data_s);
		ft_putstr_buf_n(data_s->tmp_nbrs_bfr, data_s->tmp_nbrs_bfr_index,
			data_s);
	}
}