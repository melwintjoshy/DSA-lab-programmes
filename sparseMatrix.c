#include<stdio.h>

void inputSparseMatrix(int r, int c, int sparse[])
{
    int i, j, elem, k = 0;
    for (i = 0; i < r; i++)
	{
        for (j = 0; j < c; j++) 
		{
            scanf("%d", &elem);
            if (elem != 0) 
			{
                sparse[k] = i;
                sparse[k+1] = j;
                sparse[k+2] = elem;
				k += 3;
            }
        }
    }
    
}

void printResultantMatrix(int r, int c, int a[], int b[]) 
{
    int i, j, m = 0, n = 0;
    
    printf("The resultant sparse matrix is:\n");
    for (i = 0; i < r; i++) 
	{
        for (j = 0; j < c; j++) 
		{
            if (a[m] == i && a[m + 1] == j && b[n] == i && b[n + 1] == j) 
			{
                printf("%d ", a[m + 2] + b[n + 2]);
                m += 3;
                n += 3;
            } 
			else if (a[m] == i && a[m + 1] == j) 
			{
                printf("%d ", a[m + 2]);
                m += 3;
            } 
			else if (b[n] == i && b[n + 1] == j) 
			{
                printf("%d ", b[n + 2]);
                n += 3;
            } 
			else 
			{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() 
{
    int r, c, a[45], b[45];

    printf("Sparse Matrix Addition\n");
    
    printf("Enter the number of rows: ");
    scanf("%d", &r);
    
    printf("Enter the number of columns: ");
    scanf("%d", &c);

	printf("Enter the elements of the first matrix: \n");
    inputSparseMatrix(r, c, a);

	printf("Enter the elements of the second matrix: \n");
	inputSparseMatrix(r, c, b);

    printResultantMatrix(r, c, a, b);

    return 0;
}
