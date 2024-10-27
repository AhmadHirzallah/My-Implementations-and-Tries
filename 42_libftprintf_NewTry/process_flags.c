/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:49:21 by aulicna           #+#    #+#             */
/*   Updated: 2023/02/20 17:41:07 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static void	init_format_struc(t_format *format)
// {
// 	format->hashtag = 0;
// 	format->space = 0;
// 	format->plus = 0;
// 	format->mfw = 0;
// 	format->prec = 0;
// 	format->prec_val = 0;
// 	format->min = 0;
// 	format->min_val = 0;
// 	format->zero = 0;
// }

static void	process_precision(t_prntf *pf_s)
{
	// format->prec = 1;
	pf_s->fmt_flgs.prec_fl = true;
	pf_s->fmt_flgs.prec_val = ft_atoi(pf_s->str);
	// format->prec_val = ft_atoi(&s[*i + 1]);
	// if (s[*i + 1] == '0')
	// 	*i += 1;
	while (pf_s->str == '0')
	 	pf_s->str++;
	// *i += count_digits(format->prec_val);
	pf_s->str += count_digits(pf_s->fmt_flgs.prec_val);
}

static void	process_minus(t_prntf *pf_s)
{
	pf_s->fmt_flgs.minus_fl = true;
	// format->min = 1;
	// while (s[*i] == '-')
	// 	(*i)++;
	while (pf_s->str == '-')
		pf_s->str++;
	
	pf_s->fmt_flgs.minus_val = ft_atoi(pf_s->str);
	pf_s->str += count_digits(pf_s->fmt_flgs.minus_val) - 1;
	// format->min_val = ft_atoi(&s[*i]);
	// *i += count_digits(format->min_val) - 1;
}

static void	process_minimum_width(t_prntf *pf_s)
{
	pf_s->fmt_flgs.minim_width = ft_atoi(pf_s->str);
	// format->mfw = ft_atoi(&s[*i]);
	pf_s->str += count_digits(pf_s->fmt_flgs.minim_width) - 1;
	// *i += count_digits(format->mfw) - 1;
}

void	process_flags_specifier(t_prntf *pf_s)
{
	int	i;

	// init_format_struc(format);
	// i = 0;
	// while (s[i] == '#' || s[i] == ' ' || s[i] == '+' || s[i] == '.'
		// || ('0' <= s[i] && s[i] <= '9') || s[i] == '-')
	while (ft_strchr(FLAGS, pf_s->str)
		|| (ft_strchr(DIGITS, pf_s->str)))
	{
		if (pf_s->str == '#')
			pf_s->fmt_flgs.hashtag_fl = true;
		else if (pf_s->str == ' ')
			pf_s->fmt_flgs.space_fl= true;
		else if (pf_s->str = '+')
			pf_s->fmt_flgs.plus_fl = true;
		else if (pf_s->str == '0')
			pf_s->fmt_flgs.zero_fl = true;
		else if (ft_strchr(DIGITS, pf_s->str))
			process_minimum_width(pf_s);
		else if (pf_s->str == '.')
			process_precision(pf_s);
		else if (pf_s->str == '-')
			process_minus(pf_s);
		pf_s->str++;
	}
	pf_s->specifier = pf_s->str;
	// format->specifier = s[i];
	// return (i);
	
	// {
	// 	if (s[i] == '#')
	// 		format->hashtag += 1;
	// 	else if (s[i] == ' ')
	// 		format->space += 1;
	// 	else if (s[i] == '+')
	// 		format->plus += 1;
	// 	else if (s[i] == '0')
	// 		format->zero = 1;
	// 	else if ('1' <= s[i] && s[i] <= '9')
	// 		process_mfw(format, s, &i);
	// 	else if (s[i] == '.')
	// 		process_precision(format, s, &i);
	// 	else if (s[i] == '-')
	// 		process_min(format, s, &i);
	// 	i++;
	// }
}
