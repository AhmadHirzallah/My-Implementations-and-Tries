#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>		//todo check printf
#include <stdlib.h>		//malloc and free
#include <unistd.h>		// write
#include <stdarg.h>		//variadic stuffs
#include <stdbool.h>	//false and true
#include <stddef.h>
#include "libft.h"

//	Buffer of 4k (4096 bytes)	--- Bitwise left shift
//	0000 0000 0000 0001
//	0000 0000 0000 0010
//	0001 0000 0000 0000	
# define BUFFER_SIZE		(1<<12)
# define	FLAGS			"+ 0-#"
# define SPECIFIERS		"cspdiuxX%"
# define DIGITS			"0123456789"
# define HEXADEC_LOWER	"0123456789abcdef"
# define HEXADEC_UPPER	"0123456789ABCDEF"



/*
*	ALL the bools [+-' '0#][width][.precision]
*/

typedef union	t_nbrs_uni
{
	unsigned long	uint64;
	long			int64;
}								t_nbrs_uni;


typedef enum	e_base
{
	AS_NULL = 0,
	BASE_10 = 10,
	BASE_16 = 16
}						t_e_base;

typedef enum	e_err
{
	OK = 0,
	MALLOC_ERR = -42,
	PARSE_ERR = -10
}						t_e_err;

typedef enum	e_for_nbrs
{
	AS_NULL_NOT_NEG = 0,
	NEG_NBR,
	CONVERTED_FROM_NEG
}							t_e_for_nbrs;

typedef struct s_fmt_flags
{
	//	Parsing stuff
	bool	left_justified;
	bool	plus;
	bool	space;
	bool	hashtag;
	bool	is_zero_pad;

	// "csdixXpu...."
	char	specifier;

	//	(width) and (precision)
	int	width_val;
	int	precision_val;
	int	padding_spaces;
	int	padding_zeros;

	// Base
	t_e_base						base_e;
	bool										upper_case;
	bool										is_signed_nbr;
	t_e_for_nbrs	neg_nbr_track;
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
	t_nbrs_uni	dynmic_nbr_vals;
	char	tmp_nbrs_bfr[64];
	int		tmp_nbrs_bfr_index; //tmp_nbrs_bfr index
}											t_data;

int	ft_printf(const char *fmt, ...);

#endif