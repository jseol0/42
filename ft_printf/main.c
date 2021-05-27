#include "ft_printf.h"
#include <stdio.h>

int main()
{
	printf("%%-d 42 == %-d", (int)-2147483648);
	ft_printf("%%-d 42 == %-d", (int)-2147483648);
	return (0);
}
