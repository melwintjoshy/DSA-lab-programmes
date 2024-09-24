#include <stdio.h>
#define MAX 50

int queue_arr[MAX];
int front = 0;
int rear = -1;

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
		int value = queue_arr[front];
		front = front + 1;
		return value;
	}
}

//display fn
void display()
{
	if (front > rear)
    {
        printf("QUEUE IS EMPTY\n");
        return;
    }

	for (int i = front; i <= rear ; i++)
	{
		printf("%d ", queue_arr[i]);
	}
	printf("\n");
}


//main fn
int main()
{
	int choice, data;
	
	while(1)
	{
		printf("\n");
		printf("1.ENQUEUE \n");
		printf("2.DEQUEUE \n");
		printf("3.DISPLAY \n");
		printf("4.EXIT \n");
		printf("ENTER YOUR CHOICE: ");
		scanf("%d", &choice);
		
		
		switch (choice)
		{
		  case 1: 
		  	 printf("Enter the element: ");
		  	 scanf("%d", &data);
		  	 enqueue(data);
		  	 break;
		  
		  case 2:
		  	 data = dequeue();
		  	 if ( data != -1)
		  	 printf("ELEMENT %d DEQUEUED.\n", data);
		  	 break;
		  	 
		  case 3:
		  	 display();
		  	 break;
		  case 4:
		  	 printf("Exiting...");
		  	 return 0;
		  	 break;
		  default:
		  	  printf("Wrong input");
		}
	}
}	




