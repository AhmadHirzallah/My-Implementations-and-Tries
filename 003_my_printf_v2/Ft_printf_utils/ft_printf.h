#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>		//todo check printf
#include <stdlib.h>		//malloc and free
#include <unistd.h>		// write
#include <stdarg.h>		//variadic stuffs
#include <stdbool.h>	//false and true
#include <limits.h>		// INT_MAX and more	
#include <stddef.h>
#include "../Libft/libft.h"

//	Buffer of 4k (4096 bytes)	--- Bitwise left shift
//	0000 0000 0000 0001
//	0000 0000 0000 0010
//	0001 0000 0000 0000	
#define BUFFER_SIZE		(1<<12)
#define	FLAGS			"+ 0-#"
#define SPECIFIERS		"cspdiuxX%"
#define DIGITS			"0123456789"
#define HEXADEC_UPPER	"0123456789ABCDEF"
#define HEXADEC_LOWER	"0123456789abcdef"



/*
*	ALL the bools [+-' '0#][width][.precision]
*/

typedef union
{
	unsigned long	uint64;
	long			int64;
}				t_union_trk;


typedef enum	e_base
{
	BASE_2 = 2,
	BASE_8 = 8,
	BASE_10 = 10,
	BASE_16 = 16
}						t_e_base;

typedef enum	e_err
{
	OK = 0,
	MALLOC_ERR = -42,
	PARSE_ERR = -10
}						t_e_err;

typedef struct s_fmt_flags
{
	//	Parsing stuff
	bool	left_justified;
	bool	plus;
	bool	space;
	bool	hashtag;
	bool	zero_padding;

	// "csdixXpu...."
	char	specifier;

	//	(width) and (precision)
	int	width_val;
	int	precision_val;
	int	padding_spaces;

	// Base
	t_e_base	base_e;
	bool				upper_case;
	bool				is_signed_nbr;
	bool				is_negative_nbr;
}							t_fmt_flags;

typedef	struct s_data
{
	//	string pointer copy to fmt string
	//	variadic list variables. (argument pointer)
	//	count chars written
	//	buffer in the HEAP
	//	buffer index
	const char		*str;
	va_list				ap;
	int								written_chrs_count;
	char					*buf;
	int								buf_index;
	t_fmt_flags	fmt_flags_s;
	t_union_trk	dynmic_nbr_vals;	
}											t_data;

int	ft_printf(const char *fmt, ...);
void	ft_parse_flags(t_data *data_s);


#endif