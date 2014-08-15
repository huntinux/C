

void select_sort(int array[], int n)
{
	int i, j;
	int min_index;

	// min(0 -> n-1) --> array[0]
	// min(1 -> n-1) --> array[1]
	// min(i -> n-1) --> array[i]
	//
	for(i = 0; i < n-1; i++){
		min_index = i;
		for(j = i + 1; j < n; j++ ){
			if(array[min_index] < array[j]){	
				min_index = j;
			}
		}

		if(min_index != i)	{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;
		}
	}


}
