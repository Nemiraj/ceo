#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NODE
{
char usn[10];
char name[10];
char branch[10];
int sem;
int phno;
struct NODE *next;
}node;

node *first=NULL;
node *read_data();
void front_insert();
void front_del();
void end_insert();
void end_del();
void display();

main()
{
	int ch;
	do
	{
		printf("\n\n1.front_insert\n2.front_delete\n3.end_insert\n4.end_delete\n5.display\n6.exit\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	front_insert();
				break;
			case 2:	front_del();
				break;
			case 3:	end_insert();
				break;
			case 4:	end_del();
				break;
			case 5:	display();
				break;
			case 6:	
				break;
			default:printf("invalid choice");
		}
	}
	while(ch!=6);
	return 0;
}

node*read_data()
{
	int sem,phno;
	char usn[10],name[10], branch[10];
	node*nn;
	nn=(node*)malloc(sizeof(node));
	printf("Entar the usn: ");
	scanf("%s",usn);
	strcpy(nn->usn,usn);
	printf("Entar the name: ");
	scanf("%s",name);
	strcpy(nn->name,name);
	printf("Entar the branch: ");
	scanf("%s",branch);
	strcpy(nn->branch,branch);
	printf("Entar the sem: ");
	scanf("%d",&sem);
	nn->sem=sem;
	printf("Entar the phno: ");
	scanf("%d",&phno);
	nn->phno=phno;
nn->next=NULL;
return(nn);
}

void front_insert()
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp=read_data();
	if(first==NULL)
		first=temp;
	else
	{
		temp->next=first;
		first=temp;
	}
}

void end_insert()
{
	node *temp,*curr;
	temp=(node*)malloc(sizeof(node));
	temp=read_data();
	if(first==NULL)
		first=temp;
	else
	{
		curr=first;
		while(curr->next!=NULL)
			curr=curr->next;
		curr->next=temp;
	}
}

void front_del()
{
	node *temp;
	if(first==NULL)
		printf("list is empty\n");
	else
	{
		temp=first;
		first=first->next;
		free(temp);
	}
}

void end_del()
{
	node *curr, *prev;
	if(first==NULL)
		printf("list is empty\n");
	if(first->next==NULL)
	{
		curr=first;
		first=NULL;
		free(curr);
	}
	else
	{
		curr=first;
		while(curr->next!=NULL)
		{
			prev=curr;
			curr=curr->next;
		}
		prev->next=NULL;
		free(curr);
	}
}

void display()
{
	int count=0;
	node *temp;
	if(first==NULL)
		printf("list is empty");
	else
	{
		temp=first;
		while(temp!=NULL)
		{
			printf("\nusn:%s",temp->usn);
			printf("\nname:%s",temp->name);
			printf("\nbranch:%s",temp->branch);
			printf("\nsem:%d",temp->sem);
			printf("\nphno:%d\n",temp->phno);
			count++;
			temp=temp->next;
		}
		printf("no of nodes: %d\n\n\n",count);
	}
}

