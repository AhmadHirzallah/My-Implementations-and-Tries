#include "../../include/ft_printf_utils.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"

void	ft_itoa_base_bfr(t_data *data_s, t_nbrs_uni values_uni)
{
	t_nbrs_uni	tmp_dynm_nbr;

	if (data_s->fmt_flags_s.base_e != 10 && data_s->fmt_flags_s.base_e != 16)
		return ;
	if (CONVERTED_FROM_NEG != (data_s->fmt_flags_s.neg_nbr_track) 
			&& NEG_NBR == (data_s->fmt_flags_s.neg_nbr_track))
	{
		values_uni.int64 = -(values_uni.int64);
		data_s->fmt_flags_s.neg_nbr_track = CONVERTED_FROM_NEG;
		ft_itoa_base_bfr(data_s, values_uni); 
	}
	else if (values_uni.uint64 < data_s->fmt_flags_s.base_e)
	{
		// "xX"
		if (data_s->fmt_flags_s.upper_case)
			data_s->tmp_nbrs_bfr[data_s->tmp_nbrs_bfr_index++] = HEXADEC_UPPER[values_uni.uint64];
		else
			data_s->tmp_nbrs_bfr[data_s->tmp_nbrs_bfr_index++] = HEXADEC_LOWER[values_uni.uint64];
	}
	else
	{
		tmp_dynm_nbr.uint64 = (values_uni.uint64) / (data_s->fmt_flags_s.base_e);
		ft_itoa_base_bfr(data_s, tmp_dynm_nbr);
		tmp_dynm_nbr.uint64 = (values_uni.uint64) % (data_s->fmt_flags_s.base_e);
		ft_itoa_base_bfr(data_s, tmp_dynm_nbr);
	}
}