#include <stdio.h>
#define MAX 100

int heap[MAX];
int n = 0;

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

// Function to insert a new element into the heap
void insert(int data) {
    if (n >= MAX) {
        printf("Heap overflow!\n");
        return;
    }

    // Insert the new element at the end
    heap[n] = data;
    n++;

    // Restore the heap property by moving up the new element
    int lastNonleaf = n / 2 - 1;
    for (int i = lastNonleaf; i >= 0; i--) {
        heapify(heap, n, i);
    }
}

// Function to delete the root element from the heap
void delete() {
    if (n == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Deleted element: %d\n", heap[0]);

    // Replace the root with the last element
    heap[0] = heap[n - 1];
    n--;

    // Restore the heap property by heapifying from the root
    heapify(heap, n, 0);
}

// Function to display the heap
void display() {
    if (n == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nHeap Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
            	printf("Exiting...");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

