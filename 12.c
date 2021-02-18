#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct employee 
{
int id;
char name[15]; 
};
typedef struct employee EMP;
EMP emp[MAX];
int a[MAX];
int create(int num) 
{
int key;
key=num%100;
return key;
}
int getemp(EMP emp[],int key)
{
 printf("\n enter emp id:");
scanf("%d",&emp[key].id);
printf("\n Enter emp name:");
scanf("%s",emp[key].name);
return key;
}
void display()  
{
int i,ch;
printf("\n1.display all\n2.filtered display");
printf("\n Enter the choice:");
scanf("%d",&ch);
if(ch==1)
{
 printf("\n the hash table is:\n");
 printf("\n HTkey\t empID\t empname");
for(i=0;i<MAX;i++)
printf("\n %d\t%d\t%s",i,emp[i].id,emp[i].name);
 }
else
{
 printf("\n the hash table is:\n");
 printf("\nHTkey\t empID\t empname");
for(i=0;i<MAX;i++)
if(a[i]!=-1)
{
printf("\n %d\t%d\t%s",i,emp[i].id,emp[i].name);
continue;
}
}
}
void linear_prob(int key,int num)
{
  int flag,i,count=0;flag=0;
  if(a[key]==-1)
 {
  a[key]=getemp(emp,key);
 }
  else
 {
   printf("\n collision detected----!!!!\n");
   i=0;
  while(i<MAX)
  {
   if(a[i]!=-1)
    count++;
   else
   i++;
   }
   printf("\n collision avoided successfully using LINEAR PROBING\n");
  if(count==MAX)
  {
   printf("\n hash table is full");
   display(emp);
   exit(1);
  }
 for(i=key;i<=MAX;i++)
  if(a[i]==-1)
{
a[i]=num;
 flag=1;
 break;
 }
  i=0;
  while((i<key)&&(flag==0))
{
  if(a[i]==-1)
  {
   a[i]=num;
   flag=1; 
    break;
  }
  i++;
  }
 }
}
void main()
{
  int num,key,i;
int ans=1;
printf("\ncollision handling by linear probing:");
for(i=0;i<MAX;i++)
{
a[i]=-1;
}
 do
{
 printf("\n Enter the data:");
scanf("%d",&num);
key=create(num);
linear_prob(key,num);
printf("\n Do you wiish to continue?(1/0):");
scanf("%d",&ans);
}while(ans);
display(emp);
} 
