#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define MAX 10

void push(int a);
void pop(char c);
void display();
void postfix(char *);
int operands[MAX];
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
	postfix(exp);
	getch();
	
}
void push(int a)
{
	if(top>=(MAX-1))
	{
		printf("\n Stack Overflow");
	}
	else
	{
		operands[++top]=a;
	}
}
void pop(char c)
{
	int calc;
	if(top<0)
	{
		printf("\n Stack Underflow");
	}
	else if(top>0)
	{
		switch(c)
		{
			case '+' : calc= operands[top-1]+operands[top];
				   push(calc);
				   top--;
				   break;
			
			case '-' : calc=operands[top-1]-operands[top];
			           push(calc);
			           top--;
				   break;
			
			case '*' : calc=operands[top-1]*operands[top];
			           push(calc);
			           top--;
				   break;
			
	 		case '/' : calc=operands[top-1]/operands[top];
			           push(calc);
			           top--;
				   break;
			
			default :  printf("\nINVALID OPERATOR");
                                   break;
		}
	}
	
		
}


void postfix(char b[])
{
	int i=0;
	
	while(b[i]!='\0')
	{
		if(isdigit(b[i]))
		{
			push(b[i]);
		}
		
		else if(b[i] == '+' || b[i] == '-' || b[i] == '*' || b[i] == '/' || b[i] == '^')
		{
			pop(b[i]);
		}
		i++;
	}
		
	display();
}
void display()
{
	if(top<0)
	{
		printf("\nSTACK UNDERFLOW");
	}else
	{
		printf("\nTHE RESULT  IS:  %d",operands[top]);
		
	}
}		
					
		
			
			
			
