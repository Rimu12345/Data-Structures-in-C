#include<stdio.h>
#include<stdlib.h>


int cap;
struct Stack
{
	int top;
	int *arr;
};
struct Stack* sta;

struct Stack* create_stack(int cap)
{
	sta = (struct Stack*)malloc(sizeof(struct Stack));
	sta->top = -1;
	sta->arr = (int*)malloc(cap * sizeof(int));
	return sta;
}
// display function

void display()
{
	int i;
	printf("The stack is :");
	for( i=sta->top;i>=0;i--)
	{
		printf("%d \n",sta->arr[i]);

	}
}
// check stack if full
int is_full()
{
	if(sta->top == cap-1)
		return 999;
}

//check stack if empty
int is_empty()
{
	if(sta->top == -1)
		return 999;
}

//push

void push(int item)
{
	if(is_full(sta)==999)
	{
		printf("The stack is full, no more element can be added");
		return;
	}
	sta->arr[++sta->top] = item;
	printf("The item is pushed, top is at %d",sta->top);

}

// pop

int pop()
{
	if(is_empty(sta)==999)
	{
		printf("stack is empty, nothinhg to be popped");
		return 0;
	}

	int temp = sta->arr[sta->top--];
	printf("The popped element is :%d",temp);
}

int main()
{
	int n,m,ch;
	printf("Enter the no of element of the stack:");
	scanf("%d",&cap);
	sta = create_stack(cap);
	
	while (1)
	{
	printf("\n Enter your choice 1:push 2:pop 3:display 0:exit");
	scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter the element to be pushed:");
			scanf("%d",&m);
			push(m);
		}
		else if (ch==2)
		{
			pop();
		}
		else if(ch == 3)
		{
			display();
		}
		else
		{
			printf("Bal chire ati badho");
			exit(0);
		}

	}
}

