#include <stdio.h>

int a[10], n, i, elem, pos, k;

void create()
{
	printf("\nEnter the size of the array element: ");
	scanf("%d",&n);
	printf("\nEnter the elements of the array:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
}

void display()
{
	printf("\nThe array elements are:\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}

void insert()
{

	printf("\nEnter the position for the new element: ");
	scanf("%d",&pos);
	printf("\nEnter the element to be inserted: ");
	scanf("%d",&elem);
	for(i=n-1;i>=pos;i--)
	{
		a[i+1]=a[i];		
	}
	a[pos]=elem;
	n=n+1;
}

void del()
{
	printf("\nEnter the position for the element to be deleted: ");
	scanf("%d",&pos);
	elem=a[pos];
	for(i=n-1;i>=pos;i--)
	{
		a[i]=a[i+1];
	}	
	n=n-1;
	printf("\nThe deleted elemented is = %d",elem);
}

void main()
{
	int ch;
//clrscr();
do{
printf("\n\n_____Main_____\n");
printf("\n1.Create\n2.Display\n3.Insert\n4.Delete\n5.Exit\n");
printf("___________________");
printf("\nEnter the choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1:create();
break;
case 2:display();
break;
case 3:insert();
break;
case 4:del();
break;
case 5://exit(0);
break;
default: printf("\nInvalid choice:\n");
break;
}
}
while(ch!=5);
//getch();
}


