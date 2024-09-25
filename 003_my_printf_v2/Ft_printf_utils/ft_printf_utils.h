#ifndef	FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

#include <stdbool.h>
#include <stdarg.h>
#include "../ft_printf.h"
#include "../Libft/libft.h"

int								ft_init_data(t_data *data_s, const char *fmt);
int								ft_parse_fmt(t_data *data_s);
void	ft_parse_flags(t_data *data_s);
void	ft_extract_val(t_data *data_s, int *rtrned_val);
void	ft_fill_buffer(t_data *data_s, char c);
void	ft_flush_buffer(t_data *data_s);
void	ft_render_fmt(t_data *data_s);
void	ft_pad_buf_wth_n_chrs(char c, int precision, t_data *data_s);
void	ft_print_chr(t_data *data_s, int c);


#endif

