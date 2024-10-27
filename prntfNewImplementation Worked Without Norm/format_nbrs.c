#include "ft_printf.h"

void	ft_itoa_base_bfr(t_prntf *pf_s, t_nbr_union values_uni)
{
	t_nbr_union	tmp_nbr;

	if (pf_s->nbr_s.is_neg && (values_uni.int64 < 0))
	{
		values_uni.int64 = -1 * (values_uni.int64);
		ft_itoa_base_bfr(pf_s, values_uni);
	}
	else if ((values_uni.uint64) < (pf_s->nbr_s.nbr_base_e))
	{
		if (pf_s->specifier == 'X')
			pf_s->nbr_s.nbr_bfr[pf_s->nbr_s.nbr_bfr_len++] = \
			HEXADE_UPPER[values_uni.uint64];
		else
			pf_s->nbr_s.nbr_bfr[pf_s->nbr_s.nbr_bfr_len++] = \
			HEXADE_LOWER[values_uni.uint64];
	}
	else
	{
		tmp_nbr.uint64 = (values_uni.uint64 / pf_s->nbr_s.nbr_base_e);
		ft_itoa_base_bfr(pf_s, tmp_nbr);
		tmp_nbr.uint64 = (values_uni.uint64 % pf_s->nbr_s.nbr_base_e);
		ft_itoa_base_bfr(pf_s, tmp_nbr);
	}
}

static void	ft_render_flags_2nd_helper(t_prntf *pf_s)
{
	if (pf_s->nbr_s.is_neg)
	{
		pf_s->fmt_flgs.width--;
		pf_s->fmt_flgs.minus_value--;
	}
	if(pf_s->fmt_flgs.hashtag_fl && ft_strchr("Xx", pf_s->specifier))
	{
		if ((pf_s->fmt_flgs.width > 0) && pf_s->fmt_flgs.prec_fl)
			pf_s->fmt_flgs.width -= pf_s->nbr_s.nbr_bfr_len;
		// pf_s->fmt_flgs.width += 2;
		// pf_s->fmt_flgs.width -= pf_s->nbr_s.nbr_bfr_len;
		if (pf_s->fmt_flgs.minus_fl)
		{
			pf_s->fmt_flgs.minus_value -= 2;
			// if (!pf_s->fmt_flgs.prec_fl)
			// 	pf_s->fmt_flgs.minus_value -= pf_s->nbr_s.nbr_bfr_len;
		}
	}
	if (pf_s->fmt_flgs.space_fl)
	{
		pf_s->rtrn_value += write(1, " ", 1);
		pf_s->fmt_flgs.width--;
	}
	if (pf_s->fmt_flgs.plus_fl)
		pf_s->rtrn_value += write(1, "+", 1);
	if (!pf_s->fmt_flgs.minus_fl)
	{
		if (!pf_s->fmt_flgs.zero_fl)
			pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.width, ' ');
		if (pf_s->nbr_s.is_neg)
		{
			ft_putchar_fd('-', 1);
			pf_s->rtrn_value++;
		}
		if(pf_s->fmt_flgs.hashtag_fl)
		{
			if (pf_s->specifier == 'X')
				pf_s->rtrn_value += write(1, "0X", 2);
			else if (pf_s->specifier == 'x')
				pf_s->rtrn_value += write(1, "0x", 2);
			pf_s->fmt_flgs.width -= 2;
		}
		if (pf_s->fmt_flgs.zero_fl)
		{
			pf_s->fmt_flgs.width -= pf_s->nbr_s.nbr_bfr_len;
			pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.width, '0');

		}
		if (pf_s->specifier == 'p')
			pf_s->rtrn_value += write(1, "0x", 2);
		pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.prec_value, '0');
		pf_s->rtrn_value += write(1, pf_s->nbr_s.nbr_bfr, pf_s->nbr_s.nbr_bfr_len);
	}
	else if (pf_s->fmt_flgs.minus_fl)
	{
		if (pf_s->fmt_flgs.prec_fl && !pf_s->fmt_flgs.hashtag_fl)
			pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.prec_value, '0');
		if(pf_s->fmt_flgs.hashtag_fl)
		{
			if (pf_s->specifier == 'X')
				pf_s->rtrn_value += write(1, "0X", 2);
			else if (pf_s->specifier == 'x')
				pf_s->rtrn_value += write(1, "0x", 2);
			pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.prec_value, '0');
		}
		if (pf_s->nbr_s.is_neg)
			pf_s->rtrn_value += write(1, "-", 1);
		if (pf_s->specifier == 'p')
			pf_s->rtrn_value += write(1, "0x", 2);

		pf_s->rtrn_value += write(1, pf_s->nbr_s.nbr_bfr, pf_s->nbr_s.nbr_bfr_len);
		pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.minus_value, ' ');
	}
}

void	ft_render_flags_helper(t_prntf *pf_s)
{
	if ((0 == pf_s->nbr_s.dynmc_nbr.uint64) && ('p' == pf_s->specifier))
	{
		ft_putstr_fd("(nil)", 1);
		pf_s->rtrn_value += 5;
		return ;
	}
	if (pf_s->specifier == 'p')
	{
		pf_s->fmt_flgs.width -= (2 + pf_s->nbr_s.nbr_bfr_len);
		if (pf_s->fmt_flgs.minus_fl)
			pf_s->fmt_flgs.minus_value -= (2 + pf_s->nbr_s.nbr_bfr_len);

	}
	ft_render_flags_2nd_helper(pf_s);
}


void	ft_render_nbrs_to_buf(t_prntf *pf_s)
{
	ft_itoa_base_bfr(pf_s, pf_s->nbr_s.dynmc_nbr);
	pf_s->nbr_s.nbr_bfr[pf_s->nbr_s.nbr_bfr_len] = '\0';
	if (((pf_s->fmt_flgs.prec_fl) &&
		(pf_s->fmt_flgs.prec_value > pf_s->nbr_s.nbr_bfr_len))
		|| pf_s->fmt_flgs.minus_fl)
	{
		if ((pf_s->fmt_flgs.width > 0) && pf_s->fmt_flgs.prec_fl)
			pf_s->fmt_flgs.width -= (pf_s->fmt_flgs.prec_value);
			// pf_s->fmt_flgs.width -= (pf_s->fmt_flgs.prec_value) + pf_s->nbr_s.nbr_bfr_len;
		if (pf_s->fmt_flgs.minus_value > 0 && pf_s->fmt_flgs.prec_fl)
			pf_s->fmt_flgs.minus_value -= pf_s->fmt_flgs.prec_value;
		else if (pf_s->fmt_flgs.minus_value > 0 && pf_s->specifier != 'p')
		 	pf_s->fmt_flgs.minus_value -= pf_s->nbr_s.nbr_bfr_len;
		if (pf_s->fmt_flgs.prec_fl)
			pf_s->fmt_flgs.prec_value -= pf_s->nbr_s.nbr_bfr_len;
	}
	else if (pf_s->fmt_flgs.prec_fl && pf_s->fmt_flgs.prec_value < pf_s->nbr_s.nbr_bfr_len)
		pf_s->fmt_flgs.width -= pf_s->nbr_s.nbr_bfr_len;
	ft_render_flags_helper(pf_s);
}

void	ft_render_nbrs_specifiers(t_prntf *pf_s)
{
	ft_bzero(&pf_s->nbr_s, sizeof(pf_s->nbr_s));

	if (ft_strchr("di", pf_s->specifier))
	{
		pf_s->nbr_s.nbr_base_e = BASE_10;
		pf_s->nbr_s.dynmc_nbr.int64 = va_arg(pf_s->ap, int);
		if (pf_s->nbr_s.dynmc_nbr.int64 < 0)
			pf_s->nbr_s.is_neg = true;
	}
	else if (ft_strchr("uxX", pf_s->specifier))
	{
		pf_s->nbr_s.dynmc_nbr.uint64= va_arg(pf_s->ap, unsigned int);
		if (ft_strchr("Xx", pf_s->specifier))
			pf_s->nbr_s.nbr_base_e = BASE_16;
		else if (pf_s->specifier == 'u')
			pf_s->nbr_s.nbr_base_e = BASE_10;
	}
	else if ('p' == pf_s->specifier)
	{
		pf_s->nbr_s.dynmc_nbr.uint64= va_arg(pf_s->ap, unsigned long);
		pf_s->nbr_s.nbr_base_e = BASE_16;
	}
	ft_render_nbrs_to_buf(pf_s);
}
