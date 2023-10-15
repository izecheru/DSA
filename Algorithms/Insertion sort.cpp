void insertionSort(int arr[], int size)
{
	for(int i = 0; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while(key < arr[j] && j>=0)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}