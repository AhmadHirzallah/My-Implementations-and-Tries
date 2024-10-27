#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>


# define HEXADE_LOWER "0123456789abcdef"
# define HEXADE_UPPER "0123456789ABCDEF"
# define DIGITS "0123456789"
# define FLAGS "+ 0-#."
# define SPECIFIERS "%cspdiuxX"

typedef struct s_format
{
	bool		hashtag_fl;
	bool		space_fl;
	bool		plus_fl;	
	bool		prec_fl;
	int			prec_value;
	bool		minus_fl;
	int		minus_value;
	bool		zero_fl;
	int 		width;
	bool		itered;
}	t_format;

typedef union u_nbr_union
{
	unsigned long	uint64;
	long			int64;
}					t_nbr_union;

typedef enum e_bases
{
	NOT_SET = 0,
	BASE_10 = 10,
	BASE_16 = 16
}					t_bases_e;

typedef	struct s_nbr
{
	t_nbr_union		dynmc_nbr;
	char			nbr_bfr[64];
	int				nbr_bfr_len;
	bool			is_neg;
	t_bases_e		nbr_base_e;
}					t_nbr;


typedef struct s_prntf
{
	t_format	fmt_flgs;
	const char	*str;
	va_list		ap;
	int			rtrn_value;
	int			tmp_k;
	char		specifier;
	t_nbr		nbr_s;
}	t_prntf;


void	parse_flags_specifier(t_prntf *pf_s);
void	render_str(t_prntf *pf_s, char *str);
void	format_char(t_prntf *pf_s, char c);
int		ft_printf(const char *s, ...);
int		count_digits(int num);
int		loop_print(int *format_num, char c);
void	ft_render_nbrs_specifiers(t_prntf *pf_s);
void	ft_render_nbrs_to_buf(t_prntf *pf_s);
void	ft_itoa_base_bfr(t_prntf *pf_s, t_nbr_union values_uni);
void	ft_render_flags_helper(t_prntf *pf_s);

#endif