#include <stdio.h>
#include "include/ft_printf.h"
#include "include/libft.h"


int main()
{
	int val;


    return (0);
}
/*

	int val;


 
	val = ft_printf("%d %s %d %d %d %i %i", 9999,   "-2147483648" , (int)-2147483648 , (int)2147483648, 99, (int)-2147483648 ,(int)214748364);
	printf("\n\n%d\n\n" ,val);
	val = printf("%d %s %d %d %d %i %i", 9999,   "-2147483648" , (int)-2147483648 , (int)2147483648, 99, (int)-2147483648 ,(int)214748364);
	printf("\n\n%d\n\n" ,val);
	printf("\n\n\n\n");





	val = ft_printf("%x %X %p", 42  ,  42 , (void *)42);
	printf("\n\n%d\n\n" ,val);
	val = printf("%x %X %p", 42  ,  42 , (void *)42);
	printf("\n\n%d\n\n" ,val);
	printf("\n\n\n\n");





	val = ft_printf("%d %d %i %i", 5  ,  -55 , 9 , -99);
	printf("\n\n%d\n\n" ,val);
	val = printf("%d %d %i %i", 5  ,  -55 , 9 , -99);
	printf("\n\n\n\n");





	val = ft_printf("%s %c", "Ahmad" , 'a');
	printf("\n\n%d\n\n" ,val);
	val = printf("%s %c", "Ahmad" , 'a');
	printf("\n\n%d\n\n" ,val);
	printf("\n\n\n\n");





	val = printf("%d", ft_printf("Ahmad"));
	printf("\n%d\n" ,val);
	val = ft_printf("%d", ft_printf("Ahmad"));
	printf("\n%d\n" ,val);
	printf("\n\n\n\n");


	



	val = printf("%d", ft_printf("%d", ft_printf("%d", 10)));
	printf("\n%d\n" ,val);
	val = ft_printf("%d", ft_printf("%d", ft_printf("%d", 10)));
	printf("\n%d\n" ,val);
	printf("\n\n\n\n");





-----------------------------


	val = printf("%.3i", 0);
	printf("\n%d\n" ,val);
	printf("\n\n\n\n");
	val = ft_printf("%.3i", 0);
	printf("\n%d\n" ,val);
	printf("\n\n\n\n");



	// val = ft_printf("%010.5i", -216);
	// printf("\n%d\n" ,val);
	// printf("\n\n\n\n");
	// val = printf("%010.5i", -216);
	// printf("\n%d\n" ,val);
	///////////////////////
	val = ft_printf("my:%3.1s", "\0");
	printf("\n%d\n" ,val);
	printf("\n\n\n\n");
	val = printf("GN:%3.1s", "\0");
	printf("\n%d\n" ,val);
	printf("\n\n\n\n");



	val = ft_printf("My:%.03s", "\0");
	printf("\n%d\n" ,val);
	printf("\n\n\n\n");
	val = printf("Gn:%.03s", "\0");
	printf("\n%d\n" ,val);
	printf("\n\n\n\n");




	val = ft_printf("my3:%.0i", 0);
	printf("\n%d\n" ,val);
	val = printf("gn3:%.0i", 0);
	printf("\n%d\n" ,val);
	printf("\n\n\n\n");
	val = ft_printf("my4:%.i", 0);
	printf("\n%d\n" ,val);
	val = printf("gn4:%.i", 0);
	printf("\n%d\n" ,val);
	printf("\n\n\n\n");




--------------------------------





    val = ft_printf("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed vestibulum erat in porttitor dictum. Sed maximus varius dolor at imperdiet. Ut eu velit nunc. Donec mollis mauris at orci. "
           "Aliquam erat volutpat. Vestibulum cursus egestas luctus. Duis pretium sagittis diam, vitae lacinia odio pharetra nec. Interdum et malesuada fames ac ante ipsum primis in faucibus. Aenean consectetuer. "
           "Sed egestas justo ut augue rhoncus, sed sodales nisl ultricies. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Curabitur nec nibh quis ligula vehicula. "
           "Sed egestas justo ut augue rhoncus, sed sodales nisl ultricies. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Curabitur nec nibh quis ligula vehicula. "
           "Sed egestas justo ut augue rhoncus, sed sodales nisl ultricies. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Curabitur nec nibh quis ligula vehicula. "
           "Quisque et malesuada lorem. Donec dictum pharetra consequat. Aliquam gravida est vitae nisl sollicitudin, quis pulvinar dolor facilisis. Maecenas condimentum dolor posuere, fermentum justo et, "
           "Donec lobortis id lorem ac auctor. Maecenas lacus neque, varius eget blandit vitae, sagittis et lorem. Curabitur dolor diam, convallis et condimentum id, pellentesque eu sem. In lobortis eros arcu. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Sed egestas justo ut augue rhoncus, sed sodales nisl ultricies. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Curabitur nec nibh quis ligula vehicula. "
           "Quisque et malesuada lorem. Donec dictum pharetra consequat. Aliquam gravida est vitae nisl sollicitudin, quis pulvinar dolor facilisis. Maecenas condimentum dolor posuere, fermentum justo et, "
           "Donec lobortis id lorem ac auctor. Maecenas lacus neque, varius eget blandit vitae, sagittis et lorem. Curabitur dolor diam, convallis et condimentum id, pellentesque eu sem. In lobortis eros arcu. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Quisque et malesuada lorem. Donec dictum pharetra consequat. Aliquam gravida est vitae nisl sollicitudin, quis pulvinar dolor facilisis. Maecenas condimentum dolor posuere, fermentum justo et, "
           "Donec lobortis id lorem ac auctor. Maecenas lacus neque, varius eget blandit vitae, sagittis et lorem. Curabitur dolor diam, convallis et condimentum id, pellentesque eu sem. In lobortis eros arcu. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Quisque et malesuada lorem. Donec dictum pharetra consequat. Aliquam gravida est vitae nisl sollicitudin, quis pulvinar dolor facilisis. Maecenas condimentum dolor posuere, fermentum justo et, "
           "Donec lobortis id lorem ac auctor. Maecenas lacus neque, varius eget blandit vitae, sagittis et lorem. Curabitur dolor diam, convallis et condimentum id, pellentesque eu sem. In lobortis eros arcu. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Vivamus at sapien viverra, lacinia magna sed, sagittis lectus. Pellentesque vitae scelerisque nullam.");

	printf("\n\n%d\n\n" ,val);

    val = printf("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed vestibulum erat in porttitor dictum. Sed maximus varius dolor at imperdiet. Ut eu velit nunc. Donec mollis mauris at orci. "
           "Aliquam erat volutpat. Vestibulum cursus egestas luctus. Duis pretium sagittis diam, vitae lacinia odio pharetra nec. Interdum et malesuada fames ac ante ipsum primis in faucibus. Aenean consectetuer. "
           "Sed egestas justo ut augue rhoncus, sed sodales nisl ultricies. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Curabitur nec nibh quis ligula vehicula. "
           "Sed egestas justo ut augue rhoncus, sed sodales nisl ultricies. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Curabitur nec nibh quis ligula vehicula. "
           "Sed egestas justo ut augue rhoncus, sed sodales nisl ultricies. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Curabitur nec nibh quis ligula vehicula. "
           "Quisque et malesuada lorem. Donec dictum pharetra consequat. Aliquam gravida est vitae nisl sollicitudin, quis pulvinar dolor facilisis. Maecenas condimentum dolor posuere, fermentum justo et, "
           "Donec lobortis id lorem ac auctor. Maecenas lacus neque, varius eget blandit vitae, sagittis et lorem. Curabitur dolor diam, convallis et condimentum id, pellentesque eu sem. In lobortis eros arcu. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Sed egestas justo ut augue rhoncus, sed sodales nisl ultricies. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Curabitur nec nibh quis ligula vehicula. "
           "Quisque et malesuada lorem. Donec dictum pharetra consequat. Aliquam gravida est vitae nisl sollicitudin, quis pulvinar dolor facilisis. Maecenas condimentum dolor posuere, fermentum justo et, "
           "Donec lobortis id lorem ac auctor. Maecenas lacus neque, varius eget blandit vitae, sagittis et lorem. Curabitur dolor diam, convallis et condimentum id, pellentesque eu sem. In lobortis eros arcu. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Quisque et malesuada lorem. Donec dictum pharetra consequat. Aliquam gravida est vitae nisl sollicitudin, quis pulvinar dolor facilisis. Maecenas condimentum dolor posuere, fermentum justo et, "
           "Donec lobortis id lorem ac auctor. Maecenas lacus neque, varius eget blandit vitae, sagittis et lorem. Curabitur dolor diam, convallis et condimentum id, pellentesque eu sem. In lobortis eros arcu. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Quisque et malesuada lorem. Donec dictum pharetra consequat. Aliquam gravida est vitae nisl sollicitudin, quis pulvinar dolor facilisis. Maecenas condimentum dolor posuere, fermentum justo et, "
           "Donec lobortis id lorem ac auctor. Maecenas lacus neque, varius eget blandit vitae, sagittis et lorem. Curabitur dolor diam, convallis et condimentum id, pellentesque eu sem. In lobortis eros arcu. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Fusce varius scelerisque ultrices. Aenean id turpis a libero volutpat molestie id ac lorem. Mauris congue ex arcu, sit amet facilisis nisl lacinia id. Morbi nibh erat, molestie id congue vitae. "
           "Vivamus at sapien viverra, lacinia magna sed, sagittis lectus. Pellentesque vitae scelerisque nullam.");





--------------------------

	char *test = calloc(8000, sizeof(char));
	ft_memset(test, ' ',7999);  // 4097
	val = ft_printf("%s", test);
	printf("\n\n%d\n\n" ,val);
	val = printf("%s", test);
	printf("\n\n%d\n\n" ,val);





*/