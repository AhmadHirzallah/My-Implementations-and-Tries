#include "ft_printf.h"
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
    int value; 



    value = printf("[%-10p]\n", (void *) 42);
    printf("\nvalue is: [%d]\n\n", value);
    value = ft_printf("[%-10p]\n", (void *) 42);
    printf("\nvalue is: [%d]\n\n\n", value);









    value = printf("[%-#10X]\n", 255);
    printf("value is: [%d]\n", value);
    value = ft_printf("[%-#10X]\n", 255);
    printf("value is: [%d]\n\n\n", value);
    

    void *ptr = NULL;
    // unsigned number + %p handling !
    value = printf("[%.20i %d Hello i am ahmad %x %X [%u],,, [%p] [%p]]\n", (int)2147483647, (int)-2147483648, (int)2147483648, 42, 99,(void *)42 , ptr);
    printf("value is: [%d]\n", value);
    value = ft_printf("[%.20i %d Hello i am ahmad %x %X [%u],,, [%p] [%p]]\n", (int)2147483647, (int)-2147483648, (int)2147483648, 42, 99,(void *)42 , ptr);
    printf("\nvalue is: [%d]\n\n\n", value);






    value = printf("[%c %c %s %s]", '%', 'A', "","Ahmad");
    printf("\nvalue is: [%d]\n\n\n", value);
    value = ft_printf("[%c %c %s %s]", '%', 'A', "","Ahmad");
    printf("\nvalue is: [%d]\n\n\n", value);


    value = printf("[%04d] ", -1);
    printf("\nvalue is: [%d]\n\n\n", value);
    value = ft_printf("[%04d] ", -1);
    printf("\nvalue is: [%d]\n\n\n", value);

    value = printf("%s %s %s %s %s\n", "5" , "-5" , "55", "-2147483648", "2147483648");
    printf("\nvalue is: [%d]\n", value);
    value = ft_printf("%s %s %s %s %s\n", "5" , "-5" , "55", "-2147483648", "2147483648");
    printf("\nvalue is: [%d]\n\n\n", value);


    value = printf("%d %d %d %d %d\n", 5 , -5 , 55, (int)-2147483648, (int)2147483648);
    printf("\nvalue is: [%d]\n", value);
    value = ft_printf("%d %d %d %d %d\n", 5 , -5 , 55, (int)-2147483648, (int)2147483648);
    printf("\nvalue is: [%d]\n\n\n", value);




    value = printf("|%.5d|\n", 42);
    printf("value is: [%d]\n", value);
    value = ft_printf("|%.5d|\n", 42);
    printf("\nvalue is: [%d]\n\n\n", value);


    value = printf("|%05d|\n", 42);
    printf("value is: [%d]\n", value);
    value = ft_printf("|%05d|\n", 42);
    printf("value is: [%d]\n", value);


    value = ft_printf("|%-5d|\n", 42);
    printf("value is: [%d]\n", value);
    value = printf("|%-5d|\n", 42);
    printf("value is: [%d]\n", value);



   value = printf("[%.5s]\n", "Ahmad Omar Ibrahimm");
    printf("\nvalue is: [%d]\n\n", value);
    value = ft_printf("[%.5s]\n", "Ahmad Omar Ibrahimm");
    printf("\nvalue is: [%d]\n\n\n", value);





    value = printf("|%-10.5d|\n", 42);
    value = printf("value is: [%d]\n\n", value);
    value = ft_printf("|%-10.5d|\n", 42);
    value = printf("value is: [%d]\n\n", value);



    value = printf("|%10.5d|\n", -42);  // Expected: "|-00042|"
    value = printf("value is: [%d]\n\n", value);
    value = ft_printf("|%10.5d|\n", -42);  // Expected: "|-00042|"
    value = printf("value is: [%d]\n\n", value);



    value = printf("|%.5d|\n", 42);
    value = printf("value is: [%d]\n\n", value);
    value = ft_printf("|%.5d|\n", 42);
    value = printf("value is: [%d]\n\n", value);



    value = printf("|%.5d|\n", -42);  // Expected: "|-00042|"
    value = printf("value is: [%d]\n\n", value);
    value = ft_printf("|%.5d|\n", -42);  // Expected: "|-00042|"
    value = printf("value is: [%d]\n\n", value);


    value = ft_printf("|%5d|\n", 255);
    value = printf("value is: [%d]\n\n", value);
    value = ft_printf("|%5d|\n", 255);
    value = printf("value is: [%d]\n\n", value);









            value = printf("[%d]\n",  '%');
            value = printf("value is: [%d]\n\n", value);
            value = printf("[%d]\n", '%');
            value = printf("value is: [%d]\n\n\n\n", value);



            value = printf("[% 5.12d]\n",  1);
            value = printf("value is: [%d]\n\n", value);
            value = ft_printf("[% 5.12d]\n", 1);
            value = printf("value is: [%d]\n\n", value);





   value = printf("%s %s %s %s %s\n", "5" , "-5" , "55", "-2147483648", "2147483648");
    value = printf("value is: [%d]\n\n", value);
    value = ft_printf("%s %s %s %s %s\n", "5" , "-5" , "55", "-2147483648", "2147483648");
    value = printf("value is: [%d]\n\n", value);




    value = printf("%s\n", "Ahmad");
    printf("value is: [%d]\n\n", value);
    value = ft_printf("%s\n", "Ahmad");
    ft_printf("value is: [%d]\n", value);



    value = ft_printf("|%d|", -255);
    ft_printf("value is: [%d]\n", value);

    value = ft_printf("|%d|", -255);
    ft_printf("value is: [%d]\n", value);



    
    value = printf("%0#10X\n", 255);
    printf("value is: [%d]\n", value);
    value = ft_printf("%0#10X\n", 255);
    printf("value is: [%d]\n", value);


    value = printf("[%-#10.3X]\n", 255);
    printf("value is: [%d]\n", value);
    value = ft_printf("[%-#10.3X]\n", 255);
    printf("value is: [%d]\n", value);


    value = printf("|%-d|\n", INT_MIN);
    printf("value is: [%d]\n", value);
    value = ft_printf("|%-d|\n", INT_MIN);
    printf("value is: [%d]\n", value);


    value = printf("|%-10d|\n", 42);
    printf("value is: [%d]\n", value);
    value = ft_printf("|%-10d|\n", 42);
    printf("value is: [%d]\n", value);


    value = ft_printf("|%-10s|\n", "Hello");
    ft_printf("value is: [%d]\n", value);
    value = printf("|%-10s|\n", "Hello");
    ft_printf("value is: [%d]\n", value);


    value = ft_printf("|%10s|\n", "Hello");
    ft_printf("value is: [%d]\n", value);
    value = printf("|%10s|\n", "Hello");
    ft_printf("value is: [%d]\n", value);






    value = printf("|%.3s %.5s %.10d|\n", "1234132312" , "1234132312" , 42);  // Expected: "|  042|"
    ft_printf("value is: [%d]\n", value);
    value = ft_printf("|%.3s %.5s %.10d|\n", "1234132312" , "1234132312", 42);  // Expected: "|  042|"
    ft_printf("value is: [%d]\n", value);



    value = printf("|%04d|\n", 42);
    ft_printf("value is: [%d]\n", value);
    value = ft_printf("|%04d|\n", 42);
    ft_printf("value is: [%d]\n", value);


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








    ft_printf("|%.15d|\n", INT_MIN);
    printf("|%.15d|\n", INT_MIN);


















    return 0;
}
