

// 将有序的数组a和b，合并到c中。
void merge_two_array(int *a, int as, int *b, int bs, int *c)
{
	int i, j, k;

	i = j = k = 0;
	while(i < as && j < bs){
		
		if(a[i] <= b[j]){
			c[k++] = a[i++];
		}else{
			c[k++] = b[j++];
		}
	}

	while(i < as){
		c[k++] = a[i++];
	}

	while(j < bs){
		c[k++] = b[j++];
	}
}


void merge_array(int a[], int begin, int mid, int end, int tmp[])
{
	int i, j, k;
	int as, bs;

	i = begin;
	as = mid;
	j = mid+1;
	bs = end;
	k = 0;

	while(i <= as && j <= bs){
		
		if(a[i] <= a[j]){
			tmp[k++] = a[i++];
		}else{
			tmp[k++] = a[j++];
		}
	}

	while(i <= as){
		tmp[k++] = a[i++];
	}

	while(j <= bs){
		tmp[k++] = a[j++];
	}

	for(i = 0; i < k; i++)
		a[begin+i] = tmp[i];
}




void merge_sort(int a[], int begin, int end, int tmp[])
{
	int mid = (end+begin)/2;

	if(begin == end)
		return;

	// sub array A, B is sorted
	merge_sort(a, begin, mid, tmp);
	merge_sort(a, mid+1, end, tmp);

	// merge A and B
	merge_array(a, begin, mid, end, tmp);
	
}




int main()
{
	int a[] = {2,4,5,8};
	int b[] = {2,3,7};
	int c[10] = {0};
	int array[] = {2,1,10,7,20,88,53,42,9};
	int tmp[10] = {0};
	int i;

	//merge_two_array(a,4,b,3,c);
	merge_sort(array, 0, 9, tmp);

	for(i = 0; i < 9; i++)
		printf("%d ", array[i]);
	printf("\n");


	return 0;
}
