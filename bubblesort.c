#include <stdio.h>

void bub_sort (int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print(int arr[], int n)
{
    
    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {34,56,74,2,46,99,11};

    int n = sizeof(arr)/sizeof(arr[0]);

    bub_sort(arr,n);

    print(arr,n);

    return 0;
}

