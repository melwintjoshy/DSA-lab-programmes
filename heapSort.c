#include <stdio.h>

void heapify(int arr[], int n, int i)
{
	int temp, max, left_index, right_index;
	
	max = i;
	
	left_index = 2 * i + 1;
	right_index = 2 * i + 2;
	
	if(left_index < n && arr[left_index] > arr[max])
	{
		max = left_index;
	}
	
	if(right_index < n && arr[right_index] > arr[max])
	{
		max = right_index;
	}
	
	if(max != i)
	{
		temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
		heapify(arr, n , max);
	}
	
}

void heapSort(int arr[], int n)
{
	int temp, i;                      //heapify on non leaf nodes 
	
	for(i = n / 2 - 1; i >= 0; i--)   //non leafnodes are from n/2 - 1 to 0
	{
		heapify(arr, n, i); 
	}
	
	                                 //current array is changed to max heap
	
	for(i = n - 1; i > 0; i --)		//repeatedly swaps the root(largest element) with the last element of the heap 
	{
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		heapify(arr, i, 0);			//after each swap, perform heapify on remaining heap 
	}

}


void printArray(int arr[], int n)
{
	
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main()
{
	
	int n;
	printf("Enter the number of elements: \n");
	scanf("%d", &n);
	
	int arr[n];
	printf("Enter the elements: \n");
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Array before sorting: ");
	printArray(arr, n);
	
	heapSort(arr, n);
	printf("Array after sorting: ");
	printArray(arr, n);	
	
	return 0;
}
