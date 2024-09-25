#include "Ft_printf_utils/ft_printf_utils.h"
#include "Libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>		// write
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>

void test_percent() {
    int n = 10;
    printf("\nCHARS=%d\n", n);
    ft_printf("This is a percent symbol [%%]\n");
    printf("This is a percent symbol [%%]\n");
}

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
    //rtrn = printf("\n\nThis is a original char Y[%*]\n");
	
    //printf("\nOriginal rtrn = %d\n", rtrn);
    rtrn = ft_printf("This is a ft_ char Y[%*]\n");
	printf("\nft_print rtrn = %d\n", rtrn);

}

void test_str() {
    int val;
    char *s = "Special Beam Cannon!";
    printf("\nCHARS=%d\n", 10);
    val = ft_printf("This is a str [%s]\n", s);
    printf("val is [%d]\n\n", val);
    val = printf("This is a str [%s]\n", s);
    printf("val is [%d]\n\n", val);

    printf("\nCHARS=%d\n", 10);
    val = ft_printf("This is a str [%10s]\n", s);
    printf("val is [%d]\n\n", val);
    val = printf("This is a str [%10s]\n", s);
    printf("val is [%d]\n\n", val);

    printf("\nCHARS=%d\n", 10);
    val =  ft_printf("This is a str [%.3s]\n", s);
    printf("val is [%d]\n\n", val);
    val =  printf("This is a str [%.3s]\n", s);
    printf("val is [%d]\n\n", val);

    printf("\nCHARS=%d\n", 10);
    val = ft_printf("This is a str [%10.3s]\n", s);
    printf("val is [%d]\n\n", val);
    val = printf("This is a str [%10.3s]\n", s);
    printf("val is [%d]\n\n", val);

    printf("\nCHARS=%d\n", 10);
    val = ft_printf("my: This is a str [%*ak.*s]", 3, 6, s);
    printf("val is [%d]\n\n", val);
    val = printf("\nmain: This is a str [%*.*s]\n", 3, 6, s);
    printf("val is [%d]\n\n", val);
}

int main() {
    int a = printf("aiw");
    printf ("%d\n", a);
    return 0;
    


    
    //test_char();
    // test_str();
   // if (stdout->_flags & 8)
    //close(1);
}