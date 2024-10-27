/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:52:36 by aulicna           #+#    #+#             */
/*   Updated: 2023/02/20 17:51:02 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prntf_s_intial(t_prntf *pf_s, const char *s)
{
	pf_s->dynmc_nbr.int64 = 0;
	pf_s->str = s;
	pf_s->tmp_k = 0;
	pf_s->rtrn_val = 0;
}

int	ft_printf(const char *s, ...)
{
	t_prntf			pf_s;

///
	// va_list			pf_s->ap;
	// unsigned int	i;
	// unsigned int	printed;
	// t_format		*format;
////


	// i = 0;
	// printed = 0;
	// va_start(pf_s->ap, s);
	va_start(pf_s.ap , s);

	while (pf_s.str)
	{
		if (*pf_s.str == '%')
		{
			ft_bzero(&pf_s.fmt_flgs, sizeof(pf_s.fmt_flgs));
			// format = (t_format *) malloc(sizeof(t_format));
			// if (!format)
				// return (0);
			process_flags_specifier(&pf_s);
			pf_s.str += 2;
			// printed += format_decision(&pf_s);
			format_decision(&pf_s);
			// free(format);
		}
		else
			pf_s.rtrn_val += write(1, pf_s.str, 1);
			// printed += write(1, &s[i++], 1);
		pf_s.str++;
	}
	va_end(pf_s.ap);
	return (pf_s.rtrn_val);
}
