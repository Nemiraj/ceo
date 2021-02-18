#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int ch, front=0, rear=-1, count=0;
char q[MAX], item;

void insert()
{
	if(count==MAX)
		printf("\nQueue is full");
	else 
	{
		rear=(rear+1)%MAX;
		q[rear]=item;
		count++;
	}
}

void del()
{
	if(count==0)
		printf("\nQueue is Empty");
	else
	{
		if(front>rear&&rear==MAX-1)
		{	front=0; rear=-1; count=0;}
		else 
		{
			item=q[front];
			printf("\nDelete item is: %c",item);
			front=(front+1)%MAX;
			count--;
		}
	}
}

void display()
{
	int i,f=front,r=rear;
	if (count==0)
		printf("\nQueue is Empty");
	else
	{
		printf("\nContants of Queue is:\n");
		for(i=f;i<=r;i++)
		{
			printf("%c\t",q[i]);
			f=(f+1)%MAX;
		}
	}
}

void main()
{
	//clrscr();
//int ch;
//void insert();
//void del();
//void display();
	do
	{
	printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
	printf("\nEnter the choice:");
	scanf("%d",&ch);

	switch(ch)
		{
		case 1: printf("\nEnter the character/item to be inserted:");
			scanf(" %c",&item);
			insert();
			break;
		case 2:	del();
			break;
		case 3:	display();
			break;
		case 4:	exit(0);
			break;
		}
	}while(ch!=4);
//getch();
}
