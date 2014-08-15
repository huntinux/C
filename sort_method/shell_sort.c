

void shell_sort(int array[], int n)
{
	int gap, i;

	gap = n/2;

	while(gap >= 1){

		// same as insert_sort. but append gap
		for(i = gap; i < n; i++){
			tmp = array[i];
			j = i - gap;
			while(j >= n && tmp<array[j]){
				array[j+gap] = array[j];
				j-=gap;
			}
			array[j+gap] = tmp;
		}

		gap /= 2;
	}




}
