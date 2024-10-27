#include "ft_printf.h"

void	prntf_s_intial(t_prntf *pf_s, const char *s)
{
	pf_s->str = s;
	pf_s->tmp_k = 0;
	pf_s->rtrn_value = 0;
}

void	format_decision(t_prntf *pf_s)
{
	if (pf_s->specifier == 'c')
		format_char(pf_s , va_arg(pf_s->ap, int));
	else if (pf_s->specifier == 's')
		render_str(pf_s , va_arg(pf_s->ap, char *));
	else if (pf_s->specifier == '%')
		pf_s->rtrn_value += write(1, "%", 1);
	else if (ft_strchr("diuxXp", pf_s->specifier))
		ft_render_nbrs_specifiers(pf_s);
}

int	ft_printf(const char *s, ...)
{
	t_prntf			pf_s;

	prntf_s_intial(&pf_s, s);
	va_start(pf_s.ap , s);
	while (*pf_s.str)
	{
		if (*pf_s.str == '%' && *(++pf_s.str))
		{
			ft_bzero(&pf_s.fmt_flgs, sizeof(pf_s.fmt_flgs));
			parse_flags_specifier(&pf_s);
			format_decision(&pf_s);
		}
		else
			pf_s.rtrn_value += write(1, pf_s.str, 1);
		pf_s.str++;
	}
	va_end(pf_s.ap);
	return (pf_s.rtrn_value);
}
