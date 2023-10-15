void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int index = low - 1;
	for(int i = low; i < high; i++)
	{
		if(arr[i] <= pivot)
		{
			index++;
			swap(&arr[i], &arr[index]);
		}
	}
	swap(&arr[index + 1], &arr[high]);
	return index + 1;
}

void quickSort(int arr[], int low, int high)
{
	if(low > high || low < 0)
		return;

	int pivot = partition(arr, low, high);

	quickSort(arr, low, pivot-1);
	quickSort(arr, pivot+1, high);
}