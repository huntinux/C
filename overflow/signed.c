#include <stdio.h>

int main()
{
	signed char a=0x7f;

	printf("%d\n", a);		// 127
	printf("%d\n", ++a);	// -128

	return 0;
}

/*
 
 对于signed整型的溢出，C的规范定义是“undefined behavior”，也就是说，编译器爱怎么
 实现就怎么实现。对于大多数编译器来说，算得啥就是啥
 
 */
