#include "../../include/ft_printf.h"
#include "../../include/ft_printf_utils.h"
#include "../../include/libft.h"

void	ft_extract_val(t_data *data_s, int *rtrned_val)
{
	////	We dont need this case in our project
	if (*data_s->str == '*')
	{
		*rtrned_val = va_arg(data_s->ap, int);
		++data_s->str;
		return ;
	}

	// But if we have an number in the string or format; then no need for ; we need atoi

	//*rtrned_val = ft_atoi(data_s->str);
	// This is wrong; lets redo it below
	/////////////////////////
	*rtrned_val = 0;
	while (ft_strchr(DIGITS, (int)*data_s->str))
		*rtrned_val = (10 * (*rtrned_val)) + (*data_s->str++ - '0');
}