#include "include/ft_printf.h"
#include "include/ft_printf_utils.h"
#include "include/libft.h"
#include <unistd.h>		// write
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>


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

void test_char2(void)
{
    char c = 'A';
    int width = 10;

    ft_printf("Test 1: Basic char: [%c]\n", c);
    ft_printf("Test 2: Char with padding: [%3c]\n", c); // Right-aligned
    ft_printf("Test 3: Char with left alignment: [%-10c]\n", c);
    ft_printf("Test 4: Char with dynamic width: [%*c]\n", width, c);
    ft_printf("Test 5: Char with zero padding (invalid, should ignore): [%010c]\n", c); // Zero padding is ignored for %c
    
    
    /////////// ERRROR TO HAAAAAANDLEEE
    //printf("Test 5: Char with zero padding (invalid, should ignore): [%010c]\n", c); // Zero padding is ignored for %c
}

void test_str2(void)
{
    char *str = "Special Beam Cannon";
    int width = 10;
    int precision = 5;

    ft_printf("Test 1: Basic string: [%s]\n", str);
    ft_printf("Test 2: String with precision: [%.5s]\n", str); // Only first 5 characters
    ft_printf("Test 3: String with width: [%10s]\n", str); // Right-aligned
    printf("Test 3: String with width: [%10s]\n", str); // Right-aligned
    ft_printf("Test 4: String with left alignment: [%-10s]\n", str);
    ft_printf("Test 5: String with dynamic width and precision: [%*.*s]\n", width, precision, str);
    printf("Test 5: String with dynamic width and precision: [%*.*s]\n", width, precision, str);
    ft_printf("Test 6: NULL string: [%s]\n", NULL); // Should print "(null)"
  //  printf("Test 6: NULL string: [%s]\n", NULL); // Should print "(null)"
    //printf("Test 6: NULL string: [%s]\n", NULL); // Should print "(null)"
}


void test_int(void)
{
    int n = 42;
    int neg_n = -42;
    int width = 10;

    ft_printf("Test 1: Basic integer: [%d]\n", n);
    ft_printf("Test 2: Integer with width: [%10d]\n", n);
    ft_printf("Test 3: Left-aligned integer: [%-10d]\n", n);
    ft_printf("Test 4: Integer with precision: [%.5d]\n", n); // Zero-padded with precision
    ft_printf("Test 5: Integer with plus sign: [%+d]\n", n);
    ft_printf("Test 6: Negative integer: [%d]\n", neg_n);
    ft_printf("Test 7: Minimum int: [%d]\n", INT_MIN);
    ft_printf("Test 8: Maximum int: [%d]\n", INT_MAX);
    ft_printf("Test 9: Dynamic width: [%*d]\n", width, n);
}

void test_unsigned(void)
{
    unsigned int u = 4294967295;
    unsigned int n = 42;

    ft_printf("[%#17.4X]\n", n);
    printf("[%#17.4X]\n\n\n", n);

    ft_printf("Test 4: Unsigned with precision: [%.5u]\n", n);
    printf("Test 4: Unsigned with precision: [%.5u]\n", n);
    ft_printf("Test 4: Unsigned with precision: [%10.5u]\n", n);
    printf("Test 4: Unsigned with precision: [%10.5u]\n", n);
    ft_printf("Test 1: Basic unsigned integer: [%u]\n", u);
    ft_printf("Test 2: Unsigned with width: [%20u]\n", u);
    printf("Test 2: Unsigned with width: [%20u]\n", u);
    ft_printf("Test 3: Unsigned with leading zeros: [%010u]\n", u);
    printf("Test 3: Unsigned with leading zeros: [%010u]\n", u);
    ft_printf("Test 5: Hexadecimal lowercase: [%x]\n", n);
    printf("Test 5: Hexadecimal lowercase: [%x]\n", n);
    ft_printf("Test 6: Hexadecimal uppercase: [%X]\n", n);
    printf("Test 6: Hexadecimal uppercase: [%X]\n", n);
    ft_printf("Test 5: Hexadecimal lowercase: [%#x]\n", n);
    printf("Test 5: Hexadecimal lowercase: [%#x]\n", n);
    ft_printf("Test 6: Hexadecimal uppercase: [%#X]\n", n);
    printf("Test 6: Hexadecimal uppercase: [%#X]\n", n);
    ft_printf("Test 5: Hexadecimal lowercase: [%#17x]\n", n);
    printf("Test 5: Hexadecimal lowercase: [%#17x]\n", n);
    ft_printf("Test 6: Hexadecimal uppercase: [%#17X]\n", NULL);
    //ft_printf("Test 7: Octal: [%o]\n", n);
}

void test_pointer(void)
{
    int *ptr = NULL;
    int n = 42;

    ft_printf("Test 1: Null pointer: [%p]\n", ptr);
    printf("Test 1: Null pointer: [%p]\n", ptr);
    ft_printf("Test 2: Valid pointer: [%15p]\n", &n);
    printf("Test 2: Valid pointer: [%15p]\n", &n);
    ft_printf("Test 3: Pointer with width: [%20p]\n", &n);
    printf("Test 3: Pointer with width: [%20p]\n", &n);
    ft_printf("Test 4: Pointer with left alignment: [%-20p]\n", &n);
    printf("Test 4: Pointer with left alignment: [%-20p]\n", &n);
}

void test_percent2(void)
{
    ft_printf("Test 1: Percent symbol: [%%]\n");
    ft_printf("Test 2: Percent with width: [%10%%]\n");
    ft_printf("Test 3: Percent with left alignment: [%-10%%]\n");
}

void test_combined(void)
{
    int n = 42;
    int width = 8;
    int precision = 5;

    ft_printf("Test 1: Combining width and precision for integer: [%10.5d]\n", n);
    ft_printf("Test 2: Left-aligned with width and precision: [%-10.5d]\n", n);
    ft_printf("Test 3: Zero-padded with width and precision: [%010.5d]\n", n);
    ft_printf("Test 4: Dynamic width and precision for unsigned: [%*.*u]\n", width, precision, n);
    ft_printf("Test 5: Dynamic width and precision for hexadecimal: [%*.*x]\n", width, precision, n);
    ft_printf("Test 6: Combining flags and width for percent: [%#010x]\n", n);
}

void test_edge_cases(void)
{
    unsigned int large_value = 4294967295;
    int neg_value = -42;

    ft_printf("Test 1: Large unsigned value: [%u]\n", large_value);
    ft_printf("Test 2: Negative value for unsigned (undefined behavior): [%u]\n", neg_value);
    ft_printf("Test 3: Combined flags and large width: [%#020x]\n", large_value);
    ft_printf("Test 4: Very large precision and width: [%100.50d]\n", 12345);
}

// void test_str() {
//     int val;
//     char *s = "Special Beam Cannon!";
//     printf("\nCHARS=%d\n", 10);
//     val = ft_printf("This is a str [%s]\n", s);
//     printf("val is [%d]\n\n", val);
//     val = printf("This is a str [%s]\n", s);
//     printf("val is [%d]\n\n", val);

//     printf("\nCHARS=%d\n", 10);
//     val = ft_printf("This is a str [%10s]\n", s);
//     printf("val is [%d]\n\n", val);
//     val = printf("This is a str [%10s]\n", s);
//     printf("val is [%d]\n\n", val);

//     printf("\nCHARS=%d\n", 10);
//     val =  ft_printf("This is a str [%.3s]\n", s);
//     printf("val is [%d]\n\n", val);
//     val =  printf("This is a str [%.3s]\n", s);
//     printf("val is [%d]\n\n", val);

//     printf("\nCHARS=%d\n", 10);
//     val = ft_printf("This is a str [%10.3s]\n", s);
//     printf("val is [%d]\n\n", val);
//     val = printf("This is a str [%10.3s]\n", s);
//     printf("val is [%d]\n\n", val);

//     printf("\nCHARS=%d\n", 10);
//     val = ft_printf("my: This is a str [%*ak.*s]", 3, 6, s);
//     printf("val is [%d]\n\n", val);
//     val = printf("\nmain: This is a str [%*.*s]\n", 3, 6, s);
//     printf("val is [%d]\n\n", val);
// }

int main() 
{
   // test_unsigned();
    test_pointer();

    //test_char();
    // test_str();
   // if (stdout->_flags & 8)
    //close(1);
}