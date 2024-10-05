#include "include/ft_printf.h"
#include "include/libft.h"
#include <unistd.h>		// write
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>



    /*ft_printf("\n\n");
    printf("%d \n", printf("wasa  \n%d", printf("wasa")));
    ft_printf("%d \n", printf("wasa  \n%d", printf("wasa")));
    ft_printf("\n\n");*/
// %11p 8  "   0x8888388221"
// % i --> " 3""
// %+i --> " +3""
int main() {

    ft_printf("my [%04d] ", -1);
    printf(" [%04d] ", -1);
    return 0;
}