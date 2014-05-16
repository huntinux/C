#include <stdio.h>

int main()
{
	signed char a = 0x7f;
	signed char b = 0x05;
	signed char c = a*b;

	printf("%d\n", a*b);	// 635
	printf("%d\n", c);		// 123

	return 0;
}


// 所以signed溢出也有可能是个正数
