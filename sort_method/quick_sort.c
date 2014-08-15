



int partation(int array[], int low, int high)
{
	int pivotkey;

	pivotkey = array[low];

	while(low < high){
		while(low < high && array[high] > pivotkey)
			high--;
		array[low] = array[high];
		while(low < high && array[low] < pivotkey)
			low++;
		array[high] = array[low];
	}

	array[low] = pivotkey;

	return low;
}



void quick_sort(int array[], int low, int high)
{
	int pivot;

	if(low < high) {
		pivot = partation(array, 0, n-1);
		quick_sort(array, 0, pivot - 1);
		quick_sort(array, pivot + 1, n-1);
	}
}
