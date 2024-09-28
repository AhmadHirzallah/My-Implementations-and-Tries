#include "include/ft_printf.h"
#include "include/ft_printf_utils.h"
#include "include/libft.h"
#include <unistd.h>		// write
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

#include <stdio.h>

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <limits.h>

void test_basic_characters_and_strings() {
    int ret1, ret2;
    
    printf("Testing basic characters and strings:\n");

    ret1 = printf("Character: %c\n", 'A');
    ret2 = ft_printf("Character: %c\n", 'A');
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");

    ret1 = printf("String: %s\n", "Hello, World!");
    ret2 = ft_printf("String: %s\n", "Hello, World!");
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");

    ret1 = printf("Empty String: %s\n", "");
    ret2 = ft_printf("Empty String: %s\n", "");
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");
}

void test_integers_and_edge_values() {
    int ret1, ret2;

    printf("Testing integers and edge values:\n");

    ret1 = printf("Integer: %d\n", 42);
    ret2 = ft_printf("Integer: %d\n", 42);
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");

    ret1 = printf("Zero: %d\n", 0);
    ret2 = ft_printf("Zero: %d\n", 0);
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");

    ret1 = printf("Smallest Int: %d\n", INT_MIN);
    ret2 = ft_printf("Smallest Int: %d\n", INT_MIN);
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");
}

void test_pointers_and_null() {
    int ret1, ret2;

    printf("Testing pointers and NULL:\n");

    ret1 = printf("Pointer: %p\n", (void *)123456);
    ret2 = ft_printf("Pointer: %p\n", (void *)123456);
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");

    ret1 = printf("NULL Pointer: %p\n", NULL);
    ret2 = ft_printf("NULL Pointer: %p\n", NULL);
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");
}

void test_field_width_and_precision() {
    int ret1, ret2;

    printf("Testing field width and precision:\n");

    ret1 = printf("Zero-padded: %04d\n", 42);
    ret2 = ft_printf("Zero-padded: %04d\n", 42);
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");

    ret1 = printf("Precision: %.5d\n", 42);
    ret2 = ft_printf("Precision: %.5d\n", 42);
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");

    ret1 = printf("Precision with String: %.5s\n", "Hello");
    ret2 = ft_printf("Precision with String: %.5s\n", "Hello");
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");
}

void test_flags() {
    int ret1, ret2;

    printf("Testing flags:\n");

    ret1 = printf("Left-justified: %-5d\n", 42);
    ret2 = ft_printf("Left-justified: %-5d\n", 42);
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");

    ret1 = printf("Plus Sign: %+d\n", 42);
    ret2 = ft_printf("Plus Sign: %+d\n", 42);
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");

    ret1 = printf("Space: % d\n", 42);
    ret2 = ft_printf("Space: % d\n", 42);
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");

    ret1 = printf("Alternate: %#x\n", 42);
    ret2 = ft_printf("Alternate: %#x\n", 42);
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");
}

void test_complex_combinations() {
    int ret1, ret2;

    printf("Testing complex combinations:\n");

    ret1 = printf("Combo: %#20x\n", 42);
    ret2 = ft_printf("Combo: %#20x\n", 42);
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");

    ret1 = printf("Pointer with flags: %p\n", (void *)42);
    ret2 = ft_printf("Pointer with flags: %-#p\n", (void *)42);
    printf("Test :%d\n", ret2);

    ret1 = printf("%d %s %u %d %d \n", 1, "ah", 3, -3 -3, 3);
    ret2 = ft_printf("%d %s %u %d %d \n", 1, "ah", 3, -3 -3, 3);
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");
}

void test_special_character_width_and_flags() {
    int  ret2;

    printf("Testing special character width and flags:\n");

    //printf("Character with width: %03c\n", 'A');
    ret2 = ft_printf("\n\nCharacter with width: %03c\n", 'A');
    printf("Test %d\n",  ret2 );
}

void test_series_of_identical_conversions() {
    int ret1, ret2;

    printf("Testing series of identical conversions:\n");

    ret1 = printf("Series of integers: %d %d %d\n", 1, 2, 3);
    ret2 = ft_printf("Series of integers: %d %d %d\n", 1, 2, 3);
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");

    ret1 = printf("Series of characters: %c %c %c\n", 'A', 'B', 'C');
    ret2 = ft_printf("Series of characters: %c %c %c\n", 'A', 'B', 'C');
    printf("Test %s\n", ret1 == ret2 ? "passed" : "failed");
}

int main() {
  /*  test_basic_characters_and_strings();
    test_integers_and_edge_values();
    test_pointers_and_null();
    test_field_width_and_precision();
    test_flags();
    test_complex_combinations();
    test_special_character_width_and_flags();
    test_series_of_identical_conversions();
*/

printf("[%10p]\n", (void *)42);
ft_printf("[%10p]\n", (void *)42);
printf("%.3d\n", 1);
ft_printf("my:%.3d\n", 1);
ft_printf("my:[% .6d]\n", -42);
printf("[% .6d]\n", -42);
ft_printf("my:[%+5d]\n", -42);
printf("[%+5d]\n", -42);
ft_printf("my:[%+5d]\n", 42);
printf("[%+5d]\n", 42);
    return 0;
}