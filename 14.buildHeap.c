#include <stdio.h>

// Function to maintain the heap property
void heapify(int arr[], int n, int i) {
    int max = i;
    int left_index = 2 * i + 1;   // left child index
    int right_index = 2 * i + 2;  // right child index

    // Check if left child exists and is greater than the current max
    if (left_index < n && arr[left_index] > arr[max]) {
        max = left_index;
    }

    // Check if right child exists and is greater than the current max
    if (right_index < n && arr[right_index] > arr[max]) {
        max = right_index;
    }

    // If the max is not the current node, swap and heapify
    if (max != i) {
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
        heapify(arr, n, max);
    }
}

// Function to build a heap from an unsorted array
void buildHeap(int arr[], int n) {
    
    // Build the heap by heapifying each non-leaf node
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void display(int arr[], int n) {
    if (n == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("\nEnter the number of elements: ");
    scanf("%d",&n);
    
    int arr[n];
    printf("\nEnter the elements: ");
    for(int i = 0; i < n; i++)
    {
    scanf("%d", &arr[i]);
    }

    buildHeap(arr, n);

    printf("Heap built from array:\n");
    display(arr, n);

    return 0;
}
