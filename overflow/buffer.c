#include <stdio.h>

#define MAX_LEN 32767

int main()
{
	int len = -1;
	
//if( len < MAX_LEN) {
	if( len - MAX_LEN < 0) {
		printf("less\n");
	}else{
		printf("bigger\n");
	}


	return 0;
}
