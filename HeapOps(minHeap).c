#include <stdio.h>
#define MAX 100

int heap[MAX];
int n = 0;

void heapify(int arr[], int n, int i) {
    int min = i;
    int left_index = 2 * i + 1;
    int right_index = 2 * i + 2;

    if (left_index < n && arr[left_index] < arr[min]) {
        min = left_index;
    }
    if (right_index < n && arr[right_index] < arr[min]) {
        min = right_index;
    }
    if (min != i) {
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        heapify(arr, n, min);
    }
}

void insert(int data) {
    if (n >= MAX) {
        printf("Heap overflow!\n");
        return;
    }
    heap[n] = data;
    n++;
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(heap, n, i);
    }
}

void delete() {
    if (n == 0) {
        printf("Heap is empty!\n");
        return;
    }
    printf("Deleted element: %d\n", heap[0]);
    heap[0] = heap[n - 1];
    n--;
    heapify(heap, n, 0);
}

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
        printf("\nMin-Heap Operations:\n");
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
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
