/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:40:10 by ahirzall          #+#    #+#             */
/*   Updated: 2024/10/25 00:15:37 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fmt_handling_calculations(t_prntf *pf_s)
{
	if (pf_s->nbr_s.is_neg)
	{
		pf_s->fmt_flgs.width--;
		pf_s->fmt_flgs.minus_value--;
	}
	if (pf_s->fmt_flgs.hashtag_fl && ft_strchr("Xx", pf_s->specifier))
	{
		if ((pf_s->fmt_flgs.width > 0) && pf_s->fmt_flgs.prec_fl)
			pf_s->fmt_flgs.width -= pf_s->nbr_s.nbr_bfr_len;
		if (pf_s->fmt_flgs.minus_fl)
			pf_s->fmt_flgs.minus_value -= 2;
	}
	if (pf_s->fmt_flgs.space_fl)
	{
		pf_s->rtrn_value += write(1, " ", 1);
		pf_s->fmt_flgs.width--;
	}
}

static void	fmt_handling_not_minus_fl(t_prntf *pf_s)
{
	if (!pf_s->fmt_flgs.minus_fl)
	{
		if (!pf_s->fmt_flgs.zero_fl)
			pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.width, ' ');
		if (pf_s->nbr_s.is_neg)
			pf_s->rtrn_value += write(1, "-", 1);
		if (pf_s->fmt_flgs.hashtag_fl)
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
		pf_s->rtrn_value += write(1, pf_s->nbr_s.nbr_bfr,
				pf_s->nbr_s.nbr_bfr_len);
	}
}

static bool	fmt_handling_minus_fl(t_prntf *pf_s)
{
	if (pf_s->fmt_flgs.minus_fl)
	{
		if (pf_s->fmt_flgs.prec_fl && !pf_s->fmt_flgs.hashtag_fl)
			pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.prec_value, '0');
		if (pf_s->fmt_flgs.hashtag_fl)
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
		pf_s->rtrn_value += write(1, pf_s->nbr_s.nbr_bfr,
				pf_s->nbr_s.nbr_bfr_len);
		pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.minus_value, ' ');
		return (true);
	}
	return (false);
}

void	ft_render_flags_2nd_helper(t_prntf *pf_s)
{
	if (pf_s->fmt_flgs.plus_fl && (!pf_s->nbr_s.is_neg))
	{
		pf_s->fmt_flgs.width -= (1 + pf_s->nbr_s.nbr_bfr_len);
		pf_s->rtrn_value += loop_print(&pf_s->fmt_flgs.width, ' ');
		pf_s->rtrn_value += write(1, "+", 1);
		pf_s->rtrn_value += write(1, pf_s->nbr_s.nbr_bfr,
				pf_s->nbr_s.nbr_bfr_len);
		return ;
	}
	fmt_handling_calculations(pf_s);
	if (fmt_handling_minus_fl(pf_s))
		return ;
	else
		fmt_handling_not_minus_fl(pf_s);
}
