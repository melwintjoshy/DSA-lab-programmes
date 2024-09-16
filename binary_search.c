#include <stdio.h>

void bin_search(int arr[], int size, int key) {
    int low = 0;
    int high = size - 1;
    int found = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key) {
            printf("Element found at index %d.\n", mid);
            found = 1;
            break;
        } 
        else if (arr[mid] < key) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("Element not found.\n");
    }
}

int main() {
    int arr[] = {1, 3, 5, 6, 8};
    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);
    int n = sizeof(arr) / sizeof(arr[0]);

    bin_search(arr, n, key);

    return 0;
}
