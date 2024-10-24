#include <stdio.h>

#define MAX 100 // Maximum size of the heap

int heap[MAX];
int size = 0;

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
void insert(int value) {
    if (size >= MAX) {
        printf("Heap overflow!\n");
        return;
    }

    // Insert the new element at the end
    heap[size] = value;
    size++;

    // Restore the heap property by moving up the new element
    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(heap, size, i);
    }
}

// Function to delete the root element from the heap
void delete() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Deleted element: %d\n", heap[0]);

    // Replace the root with the last element
    heap[0] = heap[size - 1];
    size--;

    // Restore the heap property by heapifying from the root
    heapify(heap, size, 0);
}

// Function to display the heap
void display() {
    if (size == 0) {
        printf("Heap is empty!\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 0; i < size; i++) {
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

