#include<stdio.h>
#include<ctype.h>

char s[20];
int top=-1;

void push(char);
char pop();
int prior(char);

main()
{
	char infix[20],postfix[20];
	int i, j=0;
	printf("Enter the infix expression: ");
	scanf("%s",infix);
	push('#');
	for(i=0;infix[i]!='\0';i++)
	{
		if(isalnum(infix[i]))
			postfix[j++]=infix[i];
		else if(infix[i]=='(')
			push(infix[i]);
		else if(infix[i]==')')
		{
			while(s[top]!='(')
				postfix[j++]=pop();
			pop();
		}
		else
		{
		while(prior(s[top])>=prior(infix[i]))
			postfix[j++]==pop();
		push(infix[i]);
		}
	}
	while(s[top]!='#')
		postfix[j++]=pop();
	postfix[j]='\0';
	printf("postfix expression is : %s\n",postfix);
	return 0;
}

void push(char x)
{
s[++top]=x;
}

char pop()
{
	return(s[top--]);
}

int prior(char x)
{
if(x=='^')
return 3;
if(x=='*'||x=='/')
return 2;
if(x=='+'||x=='-')
return 1;
if(x=='('||x=='#')
return 0;
}

