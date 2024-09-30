#include "include/ft_printf.h"
#include "include/libft.h"
#include <unistd.h>		// write
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>



    /*ft_printf("\n\n");
   
    ft_printf("\n\n");*/
// %11p 8  "   0x8888388221"
// % i --> " 3""
// %+i --> " +3""
int main() 
{

    int     val;

    val = ft_printf("|%5d|", 255);
    ft_printf("Value is: [%d]\n", val);
    val = ft_printf("|%5d|", 255);
    ft_printf("Value is: [%d]\n", val);












    return 0;
    /*
    val = ft_printf("|%d|", -255);
    ft_printf("Value is: [%d]\n", val);
    val = ft_printf("|%d|", -255);
    ft_printf("Value is: [%d]\n", val);
    val = ft_printf("%#X\n", 255);
    ft_printf("Value is: [%d]\n", val);
    val = printf("%#X\n", 255);
    ft_printf("Value is: [%d]\n", val);

    val = ft_printf("|%-d|\n", INT_MIN);
    ft_printf("Value is: [%d]\n", val);
    val = printf("|%-d|\n", INT_MIN);
    ft_printf("Value is: [%d]\n", val);
    val = ft_printf("|%-10d|\n", 42);
    ft_printf("Value is: [%d]\n", val);
    val = printf("|%-10d|\n", 42);
    ft_printf("Value is: [%d]\n", val);
    val = ft_printf("|%-10s|\n", "Hello");
    ft_printf("Value is: [%d]\n", val);
    val = printf("|%-10s|\n", "Hello");
    ft_printf("Value is: [%d]\n", val);
    val = ft_printf("|%10s|\n", "Hello");
    ft_printf("Value is: [%d]\n", val);
    val = printf("|%10s|\n", "Hello");
    ft_printf("Value is: [%d]\n", val);






    val = printf("|%.3s %.5s %.10d|\n", "1234132312" , "1234132312" , 42);  // Expected: "|  042|"
    ft_printf("Value is: [%d]\n", val);
    val = ft_printf("|%.3s %.5s %.10d|\n", "1234132312" , "1234132312", 42);  // Expected: "|  042|"
    ft_printf("Value is: [%d]\n", val);



    val = printf("|%04d|\n", 42);
    ft_printf("Value is: [%d]\n", val);
    val = ft_printf("|%04d|\n", 42);
    ft_printf("Value is: [%d]\n", val);
    ft_printf("|%05d|\n", 42);
    printf("|%05d|\n", 42);
    ft_printf("|%05d|\n", -42);
    printf("|%05d|\n", -42);
    ft_printf("|%030d|\n", INT_MAX);
    printf("|%030d|\n", INT_MAX);
    ft_printf("|%030d|\n", INT_MIN);
    printf("|%030d|\n", INT_MIN );


    ft_printf("|%.5d|\n", 42);
    ft_printf("|%.5d|\n", -42);
    ft_printf("|%.15d|\n", INT_MIN);
    printf("|%.5d|\n", 42);
    printf("|%.5d|\n", -42);
    printf("|%.15d|\n", INT_MIN);








    ft_printf("|%.5d|\n", 42);
    printf("|%.5d|\n", 42);
    ft_printf("|%.5d|\n", -42);  // Expected: "|-00042|"
    printf("|%.5d|\n", -42);  // Expected: "|-00042|"
    ft_printf("|%.15d|\n", INT_MIN);
    printf("|%.15d|\n", INT_MIN);








    ft_printf("|%.5d|\n", 42);
    printf("|%.5d|\n", 42);
    ft_printf("|%05d|\n", 42);
    printf("|%05d|\n", 42);
    ft_printf("|%-5d|\n", 42);
    printf("|%-5d|\n", 42);





    printf("[%.5s]\n", "Ahmad Omar Ibrahimm");
    ft_printf("[%.5s]\n", "Ahmad Omar Ibrahimm");

    int     val;
    void *ptr = NULL;
    val = printf("[%.20i %d Hello i am ahmad %x %X [%u],,, [%p] [%p]]\n", (int)2147483647, (int)-2147483648, (int)2147483648, 42, 99,(void *)42 , ptr);
    printf("Value is: [%d]\n", val);
    ft_printf("Value is: [%d]\n", val);
    val = ft_printf("[%.20i %d Hello i am ahmad %x %X [%u],,, [%p] [%p]]\n", (int)2147483647, (int)-2147483648, (int)2147483648, 42, 99,(void *)42 , ptr);
    printf("Value is: [%d]\n", val);
    ft_printf("Value is: [%d]\n", val);
    ft_printf("my: [%c %c %s %s]\n", '%', 'A', "","Ahmad");
    printf("[%c %c %s %s]", '%', 'A', "","Ahmad");
    int value; 
    value = ft_printf("my [%04d] ", -1);
    printf("\nmy:%d", value);
    printf("\n [%04d] ", -1);
    printf("\nGNU:%d", value);
    printf("%s %s %s %s %s\n", "5" , "-5" , "55", "-2147483648", "2147483648");
    ft_printf("%s %s %s %s %s\n", "5" , "-5" , "55", "-2147483648", "2147483648");
    printf("%d %d %d %d %d\n", 5 , -5 , 55, (int)-2147483648, (int)2147483648);
    ft_printf("%d %d %d %d %d\n", 5 , -5 , 55, (int)-2147483648, (int)2147483648);
*/
}