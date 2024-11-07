#include <stdio.h>
#define MAX 50

int queue_arr[MAX];
int front = 0;
int rear = -1;

int visited[7] ={0, 0, 0, 0, 0, 0, 0};

int adjMat[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}
};

//enqueue fn
void enqueue(int data)
{
	if (rear == MAX-1)
	{
		printf("QUEUE OVERFLOW \n");
	}	
	
	else
	{
		rear = rear + 1;
		queue_arr[rear] = data;	
    }
}

//dequeue fn
int dequeue()
{
	if (front > rear)
	{
		printf("QUEUE UNDERFLOW \n");
		return -1;		
	}	
	
	else
	{
		int elem = queue_arr[front];
		front = front + 1;
		return elem;
	}
}

void Bfs(int i)
{
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);

    while(front <= rear) //while queue is not empty
    {
        int node = dequeue();
        for (int j = 0; j < 7; j++)
				{
        	if (adjMat[node][j] == 1 && !visited[j])
                {
                  	printf("%d ", j);
                    visited[j] = 1;
                    enqueue(j);
                }
        }
		}
}
int main()
{
    int n;
    printf("Enter the node to start the DFS: ");
    scanf("%d", &n);

    Bfs(n);   
}
