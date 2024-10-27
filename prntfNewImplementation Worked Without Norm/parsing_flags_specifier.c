#include "ft_printf.h"

static void	process_minimum_width(t_prntf *pf_s)
{
	if (pf_s->fmt_flgs.minus_fl && ft_strchr(DIGITS, *pf_s->str))
	{
		pf_s->fmt_flgs.minus_value = ft_atoi(pf_s->str);
		pf_s->str += count_digits(pf_s->fmt_flgs.minus_value) - 1;
		return ;
	}
	if (pf_s->fmt_flgs.itered)
		return ;
	pf_s->fmt_flgs.width = ft_atoi(pf_s->str);
	pf_s->str += count_digits(pf_s->fmt_flgs.width) - 1;
	pf_s->fmt_flgs.itered = true;
}

static void	process_precision(t_prntf *pf_s)
{
	
	if (*pf_s->str++ == '.')
		pf_s->fmt_flgs.prec_fl = true;
	if (!ft_isdigit(*pf_s->str))
	{
		pf_s->fmt_flgs.prec_value = 0;
		if (ft_strchr(SPECIFIERS, *pf_s->str))
			pf_s->specifier = *pf_s->str;
	}
	else
	{
		pf_s->fmt_flgs.prec_value = ft_atoi(pf_s->str);
		pf_s->str += count_digits(pf_s->fmt_flgs.prec_value);
	}
}

static void	process_minus(t_prntf *pf_s)
{
	pf_s->fmt_flgs.minus_fl = true;
	while (*pf_s->str == '-')
		pf_s->str++;
	if (ft_strchr(DIGITS, *pf_s->str))
	{
		pf_s->fmt_flgs.minus_value = ft_atoi(pf_s->str);
		pf_s->str += count_digits(pf_s->fmt_flgs.minus_value) - 1;
		pf_s->fmt_flgs.itered= true;
	}
	else
		parse_flags_specifier(pf_s);
}

void	parse_flags_specifier(t_prntf *pf_s)
{
	while (ft_strchr(FLAGS, *pf_s->str)
		|| (ft_strchr(DIGITS, *pf_s->str)))
	{
		if (*pf_s->str == '#')
			pf_s->fmt_flgs.hashtag_fl = true;
		else if (*pf_s->str == ' ')
			pf_s->fmt_flgs.space_fl= true;
		else if (*pf_s->str == '+')
			pf_s->fmt_flgs.plus_fl = true;
		else if (*pf_s->str == '0')
			pf_s->fmt_flgs.zero_fl = true;
		else if (ft_strchr(DIGITS, *pf_s->str))
			process_minimum_width(pf_s);
		else if (*pf_s->str == '.')
			process_precision(pf_s);
		else if (*pf_s->str == '-')
			process_minus(pf_s);
		if (!pf_s->fmt_flgs.prec_fl && pf_s->specifier != *pf_s->str)
			pf_s->str++;
	}
	if (ft_strchr(SPECIFIERS, *pf_s->str))
		pf_s->specifier = *pf_s->str;
}
