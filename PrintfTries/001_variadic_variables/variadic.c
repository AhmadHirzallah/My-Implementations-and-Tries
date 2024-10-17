#include <stdarg.h>
#include <stdio.h>


float	average(int n, ...)
{
	va_list	arg_ptr;	//pointing to the first argument which is n
	int avg_result;
	int	i;

	va_start(arg_ptr, n);	// n is not a normal arugment ; it is a signal argument which tell info like how many argument will be after it.
	avg_result = 0;
	i = -1;
	while (++i < n)
		avg_result += va_arg(arg_ptr, int);

	va_end(arg_ptr);
	return ((float)avg_result / n);
}

int	main()
{
	float	avg_age;
					  // this 5 is a flag
	avg_age = average(3, 		10, 15, 20);
	printf("The average age of those 3 people is : (%f)\n", avg_age);


}