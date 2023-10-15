int binarySearch(int searchElement, int arr[], int low, int high)
{
	int mid = (low + high) / 2;

	if(searchElement == arr[mid])
		return mid;

	if(searchElement > arr[mid])
	{
		return binarySearch(searchElement, arr, mid + 1, high);
	}
	else
	{
		return binarySearch(searchElement, arr, low, mid - 1);
	}
}