#include <stdio.h>


typedef enum{false=0,true=!false} bool;

void print_array(const int array[], int n)
{
	int i;
	for(i = 0; i < n; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

void adjust_heap(int array[], int n)
{
	int i, tmp;
	int pindex, lchild, rchild, max_index;
	bool isok;
	
	//printf("in adjust_heap\n");
	//print_array(array, n);
	
	while(true){

		for(i = n-1; i > 0; i-=2){
			pindex = (i-1)/2; // the parent of current node
			lchild = pindex * 2 + 1; // the left child of parent
			rchild = pindex * 2 + 2; // the right child of parent
	
			// max(lchild, rchild)
			if(rchild < n)
				max_index = (array[lchild] > array[rchild]) ? lchild : rchild;
			else
				max_index = lchild;
	
			// make parent the max
			if(array[max_index] > array[pindex]){
				tmp = array[max_index];
				array[max_index] = array[pindex];
				array[pindex] = tmp;
			}
		}

		// check if is ok
		isok = true;
		for(i = 0; i <= n/2; i++){
			if(2*i+1 < n && array[i]<array[2*i+1]) {
				isok = false;
				break;
			}

			if(2*i+2 < n && array[i]<array[2*i+2]) {
				isok = false;
				break;
			}
		}

		if(isok){
			return;
		}
	}
}

void heap_sort(int array[], int n)
{
	// 1.create big heap
	//		array[i] >= array[2i+1] && array[i] >= array[2i+2]
	// 2.ouput max element, and adjust to big heap again.
	
	// 1. create big heap
	adjust_heap(array, n);
	print_array(array, n);

	// 2. output and adjust heap
	int i, tmp;
	int last_index;
	for(last_index = n-1; last_index >= 0; last_index--){
		// 1. exchange array[0] array[last_index]
		tmp = array[0];
		array[0] = array[last_index];
		array[last_index] = tmp;
		//printf("%d\n", tmp);

		// 2. adjust to max heap
		adjust_heap(array, last_index);
		print_array(array, n);
	}
}


int main()
{
	int array[] = {16, 7, 3, 20, 17, 8};
	int num = sizeof(array) / sizeof(int);

	//adjust_heap(array, num);
	//print_array(array, num);
	heap_sort(array, num);
	print_array(array, num);


	return 0;
}
