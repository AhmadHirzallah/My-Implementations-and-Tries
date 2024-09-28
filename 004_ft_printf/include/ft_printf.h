#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE (1 << 12)
# define SPECIFIERS "%cspdiuxX"
# define HEXADE_LOWER "0123456789abcdef"
# define HEXADE_UPPER "0123456789ABCDEF"
# define DIGITS "0123456789"
# define FLAGS "+ 0-#"

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

typedef enum e_rtrns
{
	OK = 0,
	MALLOC_ERR = -2,
	PARSE_ERR = -3,
	PRINTF_ERR = -1
}					t_rtrns_e;

typedef enum e_nbr_track
{
	NOT_MODIFIED = 0,
	NEG_NBR,
	CONVERTED_FRM_NEG
}					t_nbr_track_e;

typedef struct s_fmt_flags
{
	t_nbr_track_e	nbr_track;
	t_bases_e		base_e;
	bool			left_justif_fl;
	bool			plus_fl;
	bool			space_fl;
	bool			hasht_fl;
	bool			zero_pad_fl;
	bool			precision_fl;
	bool			nbr_upper_case;
	bool			is_signed_nbr;
	char			specifier;
	int				width_val;
	int				precision_val;
	int				padding_spaces_nbr;
	int				padding_zeros_nbr;
}					t_fmt_flags_s;

typedef struct s_nbr_bfr
{
	char			nbr_bfr[64];
	int				nbr_bfr_len;
}					t_nbr_bfr;

typedef struct s_data
{
	t_fmt_flags_s	flags_s;
	t_nbr_union		dynmc_nbr;
	t_nbr_bfr		nbr_s;
	const char		*str;
	va_list			ap;
	int				rtrn_printf_value;
	char			*printf_buffer;
	char			printf_buf_len;
}					t_data_s;

int					ft_parse_fmt(t_data_s *data_s);
void				ft_flush_buffer(t_data_s *data_s);
void				ft_render_into_buffer(t_data_s data_s);
void				ft_render_char_to_buf(t_data_s *data_s, int c);
void				ft_add_n_chrs_into_bfr(t_data_s *data_s, int len, char c);
void	ft_render_str_to_buf(t_data_s *data_s, char *str_arg);

#endif