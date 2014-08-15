

void insert_sort(int array[], unsigned int n)
{
	int i, j;
	int tmp;
//
//	for(j = 1; j < n; j++){
//		
//		tmp = array[j];
//		for(i = j - 1; i >= 0; i--){
//			if(tmp < array[i]){
//				array[i+1] = array[i]; // move back
//			}else{
//				array[i+1] = tmp;
//				break;
//			} 
//		}
//	}

	for(j = 1; j < n; j++){
		tmp = array[j];
		i = j - 1;

		while(i >= 0 && tmp < array[i]){
			array[i+1] = array[i];
			i--;
		}
		array[i+1] = tmp;

	}



}
