/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_nbrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:40:10 by ahirzall          #+#    #+#             */
/*   Updated: 2024/10/25 00:15:52 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_render_flags_helper(t_prntf *pf_s)
{
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
	if ((0 == pf_s->nbr_s.dynmc_nbr.uint64) && ('p' == pf_s->specifier))
	{
		ft_putstr_fd("(nil)", 1);
		pf_s->rtrn_value += 5;
		return ;
	}
	if (((pf_s->fmt_flgs.prec_fl)
			&& (pf_s->fmt_flgs.prec_value > pf_s->nbr_s.nbr_bfr_len))
		|| pf_s->fmt_flgs.minus_fl)
	{
		if ((pf_s->fmt_flgs.width > 0) && pf_s->fmt_flgs.prec_fl)
			pf_s->fmt_flgs.width -= (pf_s->fmt_flgs.prec_value);
		if (pf_s->fmt_flgs.minus_value > 0 && pf_s->fmt_flgs.prec_fl)
			pf_s->fmt_flgs.minus_value -= pf_s->fmt_flgs.prec_value;
		else if (pf_s->fmt_flgs.minus_value > 0 && pf_s->specifier != 'p')
			pf_s->fmt_flgs.minus_value -= pf_s->nbr_s.nbr_bfr_len;
		if (pf_s->fmt_flgs.prec_fl)
			pf_s->fmt_flgs.prec_value -= pf_s->nbr_s.nbr_bfr_len;
	}
	else if (pf_s->fmt_flgs.prec_fl
		&& pf_s->fmt_flgs.prec_value < pf_s->nbr_s.nbr_bfr_len)
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
		pf_s->nbr_s.dynmc_nbr.uint64 = va_arg(pf_s->ap, unsigned int);
		if (ft_strchr("Xx", pf_s->specifier))
			pf_s->nbr_s.nbr_base_e = BASE_16;
		else if (pf_s->specifier == 'u')
			pf_s->nbr_s.nbr_base_e = BASE_10;
	}
	else if ('p' == pf_s->specifier)
	{
		pf_s->nbr_s.dynmc_nbr.uint64 = va_arg(pf_s->ap, unsigned long);
		pf_s->nbr_s.nbr_base_e = BASE_16;
	}
	ft_render_nbrs_to_buf(pf_s);
}
