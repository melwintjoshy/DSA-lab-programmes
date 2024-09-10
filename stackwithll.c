#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int val;
	struct node *next;
} *top = NULL;


//push fn

void push(int data)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->val = data;
	temp->next = top;
	top = temp;	
}

//pop fn 

void pop()
{
	if (top == NULL)
	{
		printf("Empty stack");
	}
	
	else 
	{
		printf("%d popped", top->val);
		struct node *temp = top;
		top = top->next;
		free(temp);
	}
}

//display fn

void display()
{
	if (top == NULL)
	{
		printf("Empty stack");
	}
	
	else 
	{
		struct node *temp = top;
		while(temp != NULL)
		{
			printf("%d ", temp->val);
			temp = temp->next;
		}
	}
}

//main fn

int main()
{
	int choice, data;
	
	while(1)
	{
		printf("1.PUSH \n");
		printf("2.POP \n");
		printf("3.DISPLAY \n");
		printf("4.EXIT \n");
		printf("ENTER YOUR CHOICE: ");
		scanf("%d", &choice);
		
		
		switch (choice)
		{
		  case 1: 
		  	 printf("Enter the element: ");
		  	 scanf("%d", &data);
		  	 push(data);
		  	 break;
		  
		  case 2:
		  	 pop();
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


