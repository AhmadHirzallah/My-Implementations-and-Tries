#include "ft_printf.h"

static void	format_str_null(t_prntf *pf_s)
{
	if (pf_s->fmt_flgs.width > 0 || pf_s->fmt_flgs.minus_value > 0)
	{
		if (pf_s->fmt_flgs.prec_fl && pf_s->fmt_flgs.prec_value < 6)
		{
			pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.width, ' ');
			pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.minus_value, ' ');
			return ;
		}
	}
	if (pf_s->fmt_flgs.prec_fl && pf_s->fmt_flgs.prec_value < 6)
		return ;
	else
	{
		if (pf_s->fmt_flgs.minus_fl)
		{
			ft_putstr_fd("(null)", 1);
			pf_s->fmt_flgs.minus_value -= 6;
			pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.minus_value, ' ');
		}
		else
		{
			pf_s->fmt_flgs.width -= 6;
			pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.width, ' ');
			ft_putstr_fd("(null)", 1);
		}
		pf_s->rtrn_value += 6;
	}
}

static void	render_fmted_str_wth_minus(t_prntf *pf_s, char *str)
{
	pf_s->tmp_k = 0;
	if (pf_s->fmt_flgs.prec_fl)
		while (str[pf_s->tmp_k] && (pf_s->tmp_k < pf_s->fmt_flgs.prec_value))
			ft_putchar_fd(str[pf_s->tmp_k++], 1);
	else if (pf_s->fmt_flgs.minus_fl)
		while (str[pf_s->tmp_k] && (pf_s->tmp_k < pf_s->fmt_flgs.minus_value))
			ft_putchar_fd(str[pf_s->tmp_k++], 1);
	else
	{
		ft_putstr_fd(str, 1);
		pf_s->fmt_flgs.minus_value -= ft_strlen(str);
		pf_s->rtrn_value += ft_strlen(str);
		return ;
	}
	pf_s->fmt_flgs.minus_value -= pf_s->tmp_k;
	pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.minus_value, ' ');
	pf_s->rtrn_value += pf_s->tmp_k;
}

static void	format_str_wdth(t_prntf *pf_s, char *str)
{
	if (pf_s->fmt_flgs.width > pf_s->fmt_flgs.prec_value)
		pf_s->fmt_flgs.width -= pf_s->fmt_flgs.prec_value;

	else
		pf_s->fmt_flgs.width -= ft_strlen(str);
	pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.width, ' ');
	render_fmted_str_wth_minus(pf_s, str);
}

void	render_str(t_prntf *pf_s, char *str)
{
	// if (pf_s->fmt_flgs.prec_fl && )
	// {}
	if (!str)
	{
		format_str_null(pf_s);
		return ;
	}
	else if (pf_s->fmt_flgs.prec_fl || pf_s->fmt_flgs.minus_fl)
		format_str_wdth(pf_s, str);
	else
	{
		pf_s->fmt_flgs.width -= ft_strlen(str);
		pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.width, ' ');
		ft_putstr_fd(str, 1);
		pf_s->rtrn_value += ft_strlen(str);
	}
}

void	format_char(t_prntf *pf_s, char c)
{

	pf_s->tmp_k = 0;
	if (pf_s->fmt_flgs.width > 0)
	{
		pf_s->fmt_flgs.width--;
		pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.width, ' ');
	}
	ft_putchar_fd(c, 1);
	pf_s->rtrn_value ++;

	if (pf_s->fmt_flgs.minus_fl)
	{
		pf_s->fmt_flgs.minus_value--;
		pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.width, ' ');
	}
}
