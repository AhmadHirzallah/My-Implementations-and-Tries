#ifndef	FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <stdio.h>		//todo check printf
# include <stdlib.h>		//malloc and free
# include <unistd.h>		// write
# include <stdarg.h>		//variadic stuffs
# include <stdbool.h>	//false and true
# include <limits.h>		// INT_MAX and more	
# include <stddef.h>
# include "libft.h"
# include "ft_printf.h"

int								ft_init_data(t_data *data_s, const char *fmt);
int								ft_parse_fmt(t_data *data_s);
void	ft_parse_flags(t_data *data_s);
void	ft_extract_val(t_data *data_s, int *rtrned_val);
void	ft_fill_buffer(t_data *data_s, char c);
void	ft_flush_buffer(t_data *data_s);
void	ft_render_fmt(t_data *data_s);
void	ft_pad_buf_wth_n_chrs(char c, int precision, t_data *data_s);
void	ft_print_chr(t_data *data_s, int c);
void	ft_putstr_buf_n(char *str, int precision, t_data *data_s);
void	ft_print_str(t_data *data_s, char *str);
void	ft_set_str_pad_spaces(t_data *data_s, char *str);

#endif

