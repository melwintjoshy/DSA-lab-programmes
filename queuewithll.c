#include <stdio.h>
#include <stdlib.h>

struct node
{
	int val;
	struct node *next;
} *front = NULL, *rear = NULL;

//enqueue fn

void enqueue(int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->val = data;
	temp->next = NULL;
	
	if (front == NULL)
	{
		front = rear = temp;
	}
	else 
	{
		rear->next = temp;
		rear = temp;
	}
}

void dequeue()
{
	if (front == NULL)
	{
		printf("Empty queue");
	}
	else
	{	
		printf("%d dequeued.", front->val);
		struct node *temp = front;
		front = front->next;
		if (front == NULL)
		{
			rear = NULL;
		}
		free(temp);
	}
}
	
//display fn

void display()
{
	if (front == NULL)
	{
		printf("Empty queue");
	}
	
	else 
	{
		struct node *temp = front;
		while(temp != NULL)
		{
			printf("%d ", temp->val);
			temp = temp->next;
		}
		printf("\n");
	}
}	

//main fn

int main()
{
	int choice, data;
	
	while(1)
	{
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
		  	 dequeue();
		  	 break;
		  	 
		  case 3:
		  	 display();
		  	 break;
		  case 4:
		  	 printf("Exiting...");
		  	 exit(1);
		  	 break;
		  default:
		  	  printf("Wrong input");
		}
	}
}	
	
	
