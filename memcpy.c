#include <assert.h>
#include <stdio.h>

/*
man memcpy:
SYNOPSIS
       #include <string.h>

       void *memcpy(void *dest, const void *src, size_t n);

DESCRIPTION
       The  memcpy()  function  copies  n bytes from memory area src to memory area dest.  
	   The memory areas must not overlap.  Use memmove(3) if the memory areas do overlap.
*/

// 标准的memcpy没有处理区域重叠，如果区域会重叠请使用memmove

void *
memcpy(void *dest, const void *src, size_t n)
{
	char *pdest; 
	const char *psrc;
	int i ;

	pdest = (char *)dest;
	psrc = (const char *)src;

	assert(pdest!=NULL && psrc!=NULL);

	// 处理区域重叠问题
	if(pdest > psrc && pdest < psrc + n){
		// 如果重叠了，则从后面开始复制
		for(i=n-1; i>=0; i--){
			pdest[i] = psrc[i];
		}
	}else{
		while(n-->0){
			*pdest++ = *psrc++;		
		}
	}

	return dest;
}

int 
main()
{
	char arr[] = "helloworld";
	char *src, *dst;

	// 有重叠的两个区域
	src = arr;
	dst = arr + 4;

	printf("%s\n", (char *)memcpy(dst, src, 6));
	return 0;
}

// 写函数的时候要注意
// 1. 参数处理 
//    参数是否正确（不能为NULL）(assert)
//    不能修改的加上const
// 2. 具体问题的考虑
//    此问题中，dest和src有重叠的时候该怎么办。所以要考虑到所有情况。
