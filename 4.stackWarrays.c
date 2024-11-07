#include <stdio.h>
#define MAX 50

int stack_arr[MAX];
int top = -1;

//push fn
void push(int data)
{
	if (top == MAX-1)
	{
		printf("STACK OVERFLOW \n");
	}	
	
	else
	{
		top = top + 1;
		stack_arr[top] = data;
	}
}

//pop fn
int pop()
{
	if (top == -1)
	{
		printf("STACK UNDERFLOW \n");
		return -1;
	}	
	
	else
	{
		int value = stack_arr[top];
		top = top - 1;
		return value;
	}
}

//display fn
void display()
{
	if (top == -1)
	{
		printf("STACK UNDERFLOW \n");
		return;
	}	
	
	for (int i = top; i >= 0; i--)
	{
		printf("%d ", stack_arr[i]);
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
		  	 data = pop();
		  	 if (data != -1)
		  	 printf("ELEMENT %d POPPED.\n", data);
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





