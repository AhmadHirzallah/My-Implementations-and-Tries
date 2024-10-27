/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_decision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:46:20 by aulicna           #+#    #+#             */
/*   Updated: 2023/02/20 17:24:55 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	format_decision(t_prntf *pf_s, va_list pf_s->ap, t_format *format)
void	format_decision(t_prntf *pf_s)
{
	// unsigned int	hex;
	// int				hex_len;

	// if (format->specifier == 'c')
	// 	return (format_char(format, va_arg(pf_s->ap, int)));
	if (pf_s->specifier == 'c')
		format_char(pf_s , va_arg(pf_s->ap, int));
	// else if (format->specifier == 's')
	// 	return (format_str(format, va_arg(pf_s->ap, char *)));
	else if (pf_s->specifier == 's')
		format_str(pf_s , va_arg(pf_s->ap, char *));
	// else if (format->specifier == 'p')
	// 	return (format_pointer_hex(va_arg(pf_s->ap, unsigned long int), format));
//////	else if (pf_s->specifier == 'p')
//////		return (format_pointer_hex(pf_s, va_arg(pf_s->ap, unsigned long int), format));
	// else if (format->specifier == 'd' || format->specifier == 'i')
	// 	return (format_dec_int(va_arg(pf_s->ap, int), format));
//////	else if (ft_strchr("di", pf_s->specifier))
//////		return (format_dec_int(pf_s ,va_arg(pf_s->ap, int), format));
	// else if (format->specifier == 'u')
	// 	return (format_unsigned(va_arg(pf_s->ap, unsigned int), format));
//////	else if (pf_s->specifier == 'u')
//////		return (format_unsigned(pf_s, va_arg(pf_s->ap, unsigned int), format));
	// else if (format->specifier == 'x' || format->specifier == 'X')
	// {
	// 	hex = va_arg(pf_s->ap, unsigned int);
	// 	hex_len = find_hex_len(hex, format);
	// 	hex_len += format_hex(hex, format);
	// 	return (hex_len);
	// }
//////	else if (ft_strchr("Xx", pf_s->specifier))
	//////	{
		//////	hex = va_arg(pf_s->ap, unsigned int);
	//////		hex_len = find_hex_len(hex, format);
		//////	hex_len += format_hex(hex, format);
		//////	return (hex_len);
	//////	}
	// else if (format->specifier == '%')
	// 	return (format_char(format, '%'));
	//////	else if (pf_s->specifier == '%')
		//////	return (format_char(pf_s ,format, '%'));
	return (0);
}
