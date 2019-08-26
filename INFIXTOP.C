#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define MAX 100

void push(char a);
void pop();
int precedence(char c);
void infixtopostfix(char *);
char operators[MAX];
int top=-1;

void main()
{ 
	char exp[100];
	int i,n;
	clrscr();
	printf("Enter the no. of elememts :    ");	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the element no.%d :",i); 
		scanf("%c",&exp[i]);
		
	}
	exp[i]='\0';
	infixtopostfix(exp);
	getch();
	
}
void push(char a)
{
	if(top>=(MAX-1))
	{
		printf("\n Stack Overflow");
	}
	else
	{
		operators[++top]=a;
	}
}
void pop()
{
	if(top<0)
	{
		printf("\n Stack Underflow");
	}
	else
	{
		top--;
	}
}

int precedence(char c) 
{ 
    if(c == '^') 
    return 3; 
    else if(c == '*' || c == '/') 
    return 2; 
    else if(c == '+' || c == '-') 
    return 1; 
    else
    return -1; 
} 
void infixtopostfix(char b[])
{
	int i=0;
	int temp1,temp2;
	char c;
	while(b[i]!='\0')
	{
		if(isalpha(b[i]))
		{
			printf("%c",b[i]);
		}
		else if(b[i]=='(')
		{
			push(b[i]);
		}
		else if(b[i] == '+' || b[i] == '-' || b[i] == '*' || b[i] == '/' || b[i] == '^')
		{
			temp1=precedence(b[i]);
			temp2=precedence(operators[top]);
			if(temp1>temp2)
			{
				push(b[i]);
			}
			else
			{
				while(operators[top]!='(' && operators[top]!=')' && temp1<=temp2)
				{
					printf("%c",operators[top]);
					pop();
					temp2=precedence(operators[top]);		
				}
				push(b[i]);
			}
		}
		else if(b[i]==')')	
		{
			c=operators[top];
			while(c!='(')
			{
				pop();
				c=operators[top];
			}
		}
		
		i++;
	}
		
	if(top>-1)
	{
		c=operators[top];
		while(c!='(')
		{
			printf("%c",operators[top]);
			pop();
			c=operators[top];
		}
	}
}
		
					
		
			
			
			
