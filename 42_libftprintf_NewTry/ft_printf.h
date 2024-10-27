/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:01:23 by aulicna           #+#    #+#             */
/*   Updated: 2023/02/20 17:52:53 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "include/libft.h"
# include <stdarg.h>
# include <stdbool.h>


# define BUFFER_SIZE 4096
# define HEXADE_LOWER "0123456789abcdef"
# define HEXADE_UPPER "0123456789ABCDEF"
# define DIGITS "0123456789"
# define FLAGS "+ 0-#."

typedef struct s_format
{
	bool		hashtag_fl;
	bool		space_fl;
	bool		plus_fl;	
	bool		prec_fl;
	bool		prec_val;
	bool		minus_fl;
	bool		minus_val;
	bool		zero_fl;
	long 		minim_width;	
}	t_format;

typedef union u_nbr_union
{
	unsigned long	uint64;
	long			int64;
}					t_nbr_union;


typedef struct s_prntf
{
	t_format	fmt_flgs;
	const char	*str;
	va_list		ap;
	int			rtrn_val;
	t_nbr_union	dynmc_nbr;
	int			tmp_k;
	char		specifier;
}	t_prntf;


// ***Formating functions***
// Char
int					format_char(t_format *format, char c);

// Str
void				format_str(t_format *format, char *str);

// Dec - 1st file
int					format_dec_int(int num, t_format *format);
// Dec - 2nd file
int					format_dec_int_minimal_int(t_format *format);
int					format_dec_int_prec_min_negative(int num, t_format *format);
int					format_dec_int_prec_min_positive(int num, t_format *format);

// Unsigned - 1st file
int					format_unsigned(unsigned int num, t_format *format);
unsigned int		unsigned_ft_n_len(unsigned int n);
void				ft_putunsigned_fd(unsigned int n, int fd);
// Unsigned - 2nd file
int					format_unsigned_p_m(unsigned int num, t_format *format);
int					format_unsigned_prec_min_zero(t_format *format);

// Hex - 1st file
int					format_hex(unsigned long int num, t_format *format);
int					find_hex_len(unsigned long int num, t_format *format);
void				format_hex_rec(unsigned long int num, t_format *format);
// Hex - 2nd file
int					format_hex_zero(t_format *format);

// Pointer 
int					format_pointer_hex(unsigned long int add, t_format *format);

// Format decision
void				format_decision(t_prntf *pf_s);

// Functions processing the flags
void				process_flags_specifier(t_prntf *pf_s);

// The one and only ft_printf
int					ft_printf(const char *s, ...);

// Complete bonuses functions
int					count_digits(int num);
int					loop_print(int *format_num, char c);

#endif
