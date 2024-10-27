/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:40:32 by aulicna           #+#    #+#             */
/*   Updated: 2023/02/20 17:07:53 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_str_null(t_prntf *pf_s)
{
	// int	printed;

	// printed = 0;
	// format->mfw -= 6;
	pf_s->fmt_flgs.minim_width -= 6;
	pf_s->rtrn_val += loop_print(&pf_s->fmt_flgs.minim_width, ' ');
	// printed += loop_print(&format->mfw, ' ');
	ft_putstr_fd("(null)", 1);
	// return (6 + printed);
}

static void	format_str_prec_min_print_string(t_prntf *pf_s, char *str)
{
	// int	print_str;
	// int	j;
	

	// if (format->prec == 1)
	if (pf_s->fmt_flgs.prec_fl)
	{
		pf_s->tmp_k = 0;
		// j = 0;
		// while (str[j] && j < format->prec_val)
		while (str[pf_s->tmp_k] && (pf_s->tmp_k < pf_s->fmt_flgs.prec_val))
		{
			// ft_putchar_fd(str[j], 1);
			// j++;
			ft_putchar_fd(str[pf_s->tmp_k], 1);
			pf_s->tmp_k++;
		}
		pf_s->fmt_flgs.minus_val -= pf_s->tmp_k;
		pf_s->rtrn_val += pf_s->tmp_k;
		// format->min_val -= j;
		// print_str = j;
	}
	else
	{
		ft_putstr_fd(str, 1);
		pf_s->fmt_flgs.minus_val -= ft_strlen(str);
		// format->min_val -= ft_strlen(str);
		pf_s->rtrn_val += ft_strlen(str);
		// print_str = ft_strlen(str);
	}
}

static int	format_str_prec_min(t_prntf *pf_s, char *str)
{
	// int	printed;
	// int	print_str;

	// printed = 0;
	// format->mfw -= format->prec_val;
	pf_s->fmt_flgs.minim_width -= pf_s->fmt_flgs.prec_val;
	// printed += loop_print(&format->mfw, ' ');
	pf_s->rtrn_val += loop_print(pf_s->fmt_flgs.minim_width, ' ');
	// print_str = format_str_prec_min_print_string(format, str);
	format_str_prec_min_print_string(pf_s, str);
	// printed += loop_print(&format->min_val, ' ');
	// return (printed + print_str);
}

void	format_str(t_prntf *pf_s, char *str)
{
	// int	printed;
	// int	str_len;

	// if (!str && format->prec && format->prec_val < 6)
	// 	return (0);
	if (!str && pf_s->fmt_flgs.prec_fl && pf_s->fmt_flgs.prec_val < 6)
		return (0);
	// else if (!str && format->prec && format->prec_val >= 6)
	// 	return (format_str_null(format));
	else if (!str && pf_s->fmt_flgs.prec_fl && pf_s->fmt_flgs.prec_val >= 6)
		return (format_str_null(pf_s));
	else if (!str)
		return (format_str_null(pf_s));
	// printed = 0;
	// str_len = ft_strlen(str);
	// if (format->prec == 1 || format->min == 1)
	// 	return (format_str_prec_min(format, str));
	if (pf_s->fmt_flgs.prec_fl || pf_s->fmt_flgs.minus_fl)
		format_str_prec_min(pf_s, str);
	// format->mfw -= str_len;
	pf_s->fmt_flgs.minim_width -= ft_strlen(str);
	// printed += loop_print(&format->mfw, ' ');
	pf_s->rtrn_val += loop_print(pf_s->fmt_flgs.minim_width, ' ');
	// ft_putstr_fd(str, 1);
	ft_putstr_fd(str, 1);
	pf_s->rtrn_val += ft_strlen(str);
	// return (str_len + printed);
}
