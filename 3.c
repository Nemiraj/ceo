#include<stdio.h>
#include<stdlib.h>

#define MAX 4

int stack[MAX],item;
int ch, top=-1, count=0, status=0;

void push(int stack[], int item)
{
if(top==(MAX-1))
	printf("\n\nStack is Overflow");
else
{
	stack[++top]=item;
	status++;
}
}


int pop(int stack[])
{
	int ret;
	if(top==-1)
		printf("\n\nStack is Underflow");
	else
	{
		ret= stack[top--];
		status--;
		printf("\nPOped element is %d",ret);
	}
return ret;
}

void pallindrome(int stack[])
{
	int i,temp;
	temp=status;
	for(i=0;i<temp;i++)
	{
		if(stack[i]==pop(stack))
			count++;
	}
	if(temp==count)
		printf("\nStack counts are palindrom");	
	else 
		
		printf("\nStack counts are not palindrom");
}

void display(int stack[])
{
	int i;	
	printf("\nTha Stack counts are :");
	if(top==-1)	
		printf("\nStack is Empty");		
	else
	{
		for(i=top;i>=0;i--)
			printf("\n-------\n|%d|",stack[i]);
		printf("\n");
	}
}

void main()
{
//clrscr();
do{
printf("\n\n___MAIN MENU___\n");
printf("\n1.PUSH(insert)in the Stack");
printf("\n2.POP(delete)from the Stack");
printf("\n3.PALINDROME check using stack");
printf("\n4.Exit(End the Execution)");
printf("\nEnter YOUR Choice: ");
scanf("%d",&ch);

switch(ch)
{
case 1:	printf("\nenter a element to be pushed:");
	scanf("%d",&item);
	push(stack,item);
	display(stack);
	break;
case 2: item=pop(stack);
	display(stack);
	break;
case 3:	pallindrome(stack);
	break;
case 4:	;break;
default:
	printf("\nEnd of execution");
}
}
while(ch!=4);
}
