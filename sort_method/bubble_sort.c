
void bubble_sort(int array[], int n )
{
	int i, j;


	for(i = n - 1; i > 0 ; i--){ 

		for(j = 0; j < i; j++){ 
			if(array[j] > array[j+1]){
				tmp = array[i];
				array[i] = array[i+1];
				array[i+1] = tmp;

		}
	}


}
