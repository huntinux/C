#include <stdio.h>

int main()
{
	unsigned char a=0xff;

	printf("%d\n",++a);

	return 0;
}

/*

 对于unsigned整型溢出，C的规范是有定义的——“溢出后的数会以2^(8*sizeof(type))作模运算”，
 也就是说，如果一个unsigned char（1字符，8bits）溢出了，会把溢出的值与256求模

   */
