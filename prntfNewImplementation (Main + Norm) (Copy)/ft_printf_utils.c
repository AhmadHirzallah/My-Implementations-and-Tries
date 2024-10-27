/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahirzall <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:40:10 by ahirzall          #+#    #+#             */
/*   Updated: 2024/10/25 00:16:42 by ahirzall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(int num)
{
	int	digits;

	if (num == 0)
		return (1);
	if (num < 0)
		num *= -1;
	digits = 0;
	while (num != 0)
	{
		digits++;
		num /= 10;
	}
	return (digits);
}

int	loop_print(int *format_num, char c)
{
	int	printed;

	printed = 0;
	while (*format_num > 0)
	{
		ft_putchar_fd(c, 1);
		*format_num -= 1;
		printed++;
	}
	return (printed);
}

void	ft_itoa_base_bfr(t_prntf *pf_s, t_nbr_union values_uni)
{
	t_nbr_union	tmp_nbr;

	if (pf_s->nbr_s.is_neg && (values_uni.int64 < 0))
	{
		values_uni.int64 = -1 * (values_uni.int64);
		ft_itoa_base_bfr(pf_s, values_uni);
	}
	else if ((values_uni.uint64) < (pf_s->nbr_s.nbr_base_e))
	{
		if (pf_s->specifier == 'X')
			pf_s->nbr_s.nbr_bfr[pf_s->nbr_s.nbr_bfr_len++] \
				= HEXADE_UPPER[values_uni.uint64];
		else
			pf_s->nbr_s.nbr_bfr[pf_s->nbr_s.nbr_bfr_len++] \
				= HEXADE_LOWER[values_uni.uint64];
	}
	else
	{
		tmp_nbr.uint64 = (values_uni.uint64 / pf_s->nbr_s.nbr_base_e);
		ft_itoa_base_bfr(pf_s, tmp_nbr);
		tmp_nbr.uint64 = (values_uni.uint64 % pf_s->nbr_s.nbr_base_e);
		ft_itoa_base_bfr(pf_s, tmp_nbr);
	}
}
