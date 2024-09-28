#include "../include/ft_printf.h"
#include "../include/libft.h"



void	ft_render_into_buffer(t_data_s *data_s)
{
	if ('%' == data_s->flags_s.specifier)
		ft_render_char_to_buf(data_s, '%');
	else if ('c' == data_s->flags_s.specifier)
		ft_render_char_to_buf(data_s, va_arg(data_s->ap, int));
	else if ('s' == data_s->flags_s.specifier)
		ft_render_str_to_buf(data_s, va_arg(data_s->ap, char *));
	else if (ft_strchr("di", (int)data_s->flags_s.specifier))
	{
		ft_render_nbrs_to_buf();

	}
	else if (ft_strchr("uxX", (int)data_s->flags_s.specifier))
	{
		ft_render_nbrs_to_buf();
		
	}
	else if ('p' == data_s->flags_s.specifier)
	{
		ft_render_nbrs_to_buf();
		
	}
}