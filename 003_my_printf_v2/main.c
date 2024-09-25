#include "Ft_printf_utils/ft_printf_utils.h"
#include "Libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>		// write
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>

void test_char() {
  //  printf("\x1b[31mTIME_CHARS=%d\x1b[0m\n", 42);
    int rtrn;

    // Replace piccolo_printf with ft_printf
    printf("This is a char G[%c]\n", 'A');
    ft_printf("This is a char Y[%c]\n\n\n", 'A');

    printf("This is a char G[%10c]\n", 'A');
    ft_printf("This is a char Y[%10c]\n\n", 'A');

    printf("\n\nThis is a char G[%-10c]\n", 'A');
    ft_printf("This is a char Y[%-10c]\n\n\n", 'A' );
   // int n = 10;
   // printf("This is a char G[%*c]\n", n, 'A');
   // ft_printf("This is a char Y[%*c]\n", 'A');
    ft_printf("This is a char Y[%c]\n", '%');
    ft_printf("This is a char Y[%%]\n");
    rtrn = printf("\n\nThis is a original char Y[%*]\n");
	printf("\nOriginal rtrn = %d\n", rtrn);
    rtrn = ft_printf("This is a ft_ char Y[%*]\n");
	printf("\nft_print rtrn = %d\n", rtrn);

}

int main() {
    test_char();
    return 0;
}
