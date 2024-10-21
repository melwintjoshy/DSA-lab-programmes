#include <stdio.h> 
 
void heapify(int arr[], int n, int i){
	int temp, maximum, left_index, right_index;
	
	maximum = i;
	
	left_index = 2 * i + 1;
	right_index = 2 * i + 2;
	
	if (left_index < n && arr[left_index] > arr[maximum]){
		maximum  = left_index;
	}
	
	if (right_index < n && arr[right_index] > arr[maximum]){
		maximum = right_index;
	}
	
	if (maximum != i){
		temp = arr[i];
		arr[i] = arr[maximum];
		arr[maximum] = temp;
		heapify(arr, n, maximum);
	}
	
}

void heapSort(int arr[], int n){
	
	int temp, i;
									     //heapify on non leaf nodes 
	for (i = (n / 2) - 1; i >=0; i--){   //==> leafnodes are from n/2 -1 to 0
		heapify(arr, n, i);
	}
	
	//current array is changed to max heap
	
	for(i = n - 1; i > 0; i--){	//repeatedly swaps the root(largest element) with the last element of the heap 
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;					
		heapify(arr, i, 0);		//after each swap, perform heapify on remaining heap 
	}	
}
	
int main() 
{ 

    int arr[] = { 20, 18, 5, 15, 3, 2 }; 
    int n = 6; 
  
    printf("Original Array : "); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
  
    printf("\n"); 
    heapSort(arr, n); 
  
    printf("Array after performing heap sort: "); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
    return 0; 
}
	
	
	
	
	
		





