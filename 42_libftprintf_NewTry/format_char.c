/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:32:27 by aulicna           #+#    #+#             */
/*   Updated: 2023/02/20 10:21:06 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	format_char(t_prntf *pf_s, t_format *format, char c)
void	format_char(t_prntf *pf_s, t_format *format, char c)
{
	// int	printed;

	// printed = 0;
	pf_s->k = 0;
	pf_s->fmt_flgs.minim_width--;
	// format->mfw -= 1;
	// printed += loop_print(&format->mfw, ' ');
	pf_s->rtrn_val += loop_print(&pf_s->fmt_flgs.minim_width, ' ');
	ft_putchar_fd(c, 1);
	if (pf_s->fmt_flgs.minus_fl)
	{
		pf_s->fmt_flgs.minus_val--;
		pf_s->rtrn_val += loop_print(&pf_s->fmt_flgs.minim_width, ' ');
	}
	// if (format->min == 1)
	// {
	// 	format->min_val -= 1;
	// 	printed += loop_print(&format->min_val, ' ');
	// }
}
