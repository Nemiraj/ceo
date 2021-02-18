#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct NODE
{
  char ssn[10];
  char name[10];
  char dept[10];
  char designation[10];
  float sal;
  int phno;
 struct NODE *left;
 struct NODE *right;
}node;
 node *first=NULL;
 node *read_data();
 void front_insert();
 void front_delete();
 void end_insert();
 void end_delete();
 void display();

int main()
{
 int ch;
 do
 {
   printf("\n1.front_insert\n2.front_delete\n3.end_insert\n4.end_delete\n5.display\n6.exit\n");
   printf("enter your choice:\n");
   scanf("%d",&ch);
   switch(ch)
 {
  case 1:front_insert();
         break;
  case 2:front_delete();
         break;
  case 3:end_insert();
         break;
  case 4:end_delete();
         break;
  case 5:display();
         break;
  case 6:exit(0);
  default:printf("invalid choice");
 }
}while(ch!=6);
 return 0;
}
 node *read_data()
{
 char ssn[10];
 char name[10];
 char dept[10];
 char designation[10];
 float sal;
 int phno;
 node *temp;
 temp=(node*)malloc(sizeof(node));
 printf("enter employee data\n");
 printf("enter ssn: ");
 scanf("%s",ssn);
 strcpy(temp->ssn,ssn);
 printf("enter name: ");
 scanf("%s",name);
 strcpy(temp->name,name);
 printf("enter department: ");
 scanf("%s",dept);
 strcpy(temp->dept,dept);
 printf("enter designation: ");
 scanf("%s",designation);
 strcpy(temp->designation,designation);
 printf("enter salary: ");
 scanf("%f",&sal);
 temp->sal=sal;
 printf("enter phno: \n");
 scanf("%d",&phno);
 temp->phno=phno;
 temp->left=NULL;
 temp->right=NULL;
 return(temp);
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
   temp->right=first;
   first->left=temp;
   first=temp;
 }
}
void end_insert()
{
 node *curr,*temp; 
 temp=(node*)malloc(sizeof(node));
 temp=read_data();
 if(first==NULL)
 first=temp;
 else
 {
 curr=first;
 while(curr->right!=NULL)
 curr=curr->right;
 curr->right=temp;
 temp->left=curr;
 }
}
void front_delete()
{
  node *temp;
 if(first==NULL)
 printf("doubly linked list is empty: ");
 else
  if(first->right==NULL)
 {
  temp=first;
   first=NULL;
   free(temp);
 }
 else 
 {
   temp=first;
   first=first->right;
   first->left=NULL;
   free(temp);
 }
}
void end_delete()
{
 node *prev,*curr;
 if(first==NULL)
 printf("doubly linked list is empty\n: ");
 else
 if(first->right==NULL)
 {
   curr=first;
   first=NULL;
   free(curr);
 }
 else
 { 
   curr=first;
 while(curr->right!=NULL)
  {
   prev=curr;
   curr=curr->right;
  }
   prev->right=NULL;
   free(curr);
 }
}
void display()
{
  int count=0;
  node *temp;
  if(first==NULL)
  printf("doubly linked list is empty\n:");
  else
   {
      temp=first;
      while(temp!=NULL)
       {
         printf("\nssn:%s",temp->ssn);
         printf("\nname:%s",temp->name);
         printf("\ndept:%s",temp->dept);
         printf("\ndesignation:%s",temp->designation);
         printf("\nsalary:%f",temp->sal);
         printf("\nphno:%d",temp->phno);
                count++;
                temp=temp->right;
       }
         printf("no of nodes:%d",count);
    }
}
