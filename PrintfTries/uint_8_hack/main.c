#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

typedef union
{
	int8_t	nbr;
	uint8_t	u_nbr;
}					t_union;


void	ft_print_val(t_union union_t, bool is_neg)
{
	if (is_neg)
	{
		putchar('-');
		union_t.nbr = -union_t.nbr;
	}
	printf("%u\n", union_t.u_nbr);
}

int main (void)
{
	t_union	union_t;

	union_t.nbr = -1;
	

	union_t.u_nbr = 200;

	return (0);
}