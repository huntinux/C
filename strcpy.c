//
// 学习使用assert
// 
//
#include <stdio.h>
#include <assert.h>

char * strcpy(const char *src, char *dst)
{
	char *result;

	assert(src!=NULL && dst != NULL);
	
	result = dst;
	while((*dst++ = *src++) != '\0')
		;

	return result;
}

int main()
{
	char str1[] = "hello world";
	char str2[64];

	//strcpy(str1, NULL);
	printf("%s\n",strcpy(str1, str2));

	return 0;
}
