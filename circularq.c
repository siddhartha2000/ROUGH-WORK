#include<stdio.h>
#define QSIZE 20

void enqueue(int *,int *,int *);
void dequeue(int *,int *,int *);
void display(int *, int *, int *);

void main()
{
	int q[QSIZE],r=-1,f=0,count=0;
	int choice2;
	char choice1='y';
	while(choice1=='y'||choice1=='Y')
	{
		printf("\n Enter choice of operation on queue: 1.ENQUEUE 2.DEQUEUE 3.DISPLAY:\n");
		scanf("%d",&choice2);
		if(choice2==1)
		{
			enqueue(q,&r,&count);
			display(q,&f,&count);
		}
		else if(choice2==2)
		{
			dequeue(q,&f,&count);
			display(q,&f,&count);
		}
		else if(choice2==3)
		{
			display(q,&f,&count);
		}
		else
		printf("\n Wrong input");
		printf("\n WANT TO CONTINUE? yes/no:enter y for yes and n for no:\t");
		fflush(stdin);
		scanf("%s",&choice1);
	}
}
void enqueue(int q[],int *r,int *count)
{
	int item;
	printf("Enter item \n");
	scanf("%d",&item);
	if((*count==QSIZE))
		printf("\n Q is full");
	else
	{	
		((*r)++)%QSIZE;
		q[*r]=item;
		(*count)++;
		printf("Value inserted=%d",item);
	}
}
void dequeue(int q[],int *f,int *count)
{
	if(*count==0)
	{
		printf("Queue is empty\n");
	}
	else 
	{
		printf("Elememt deleted is %d",q[*f]);
		((*f)++)%QSIZE;
		*count--;
	}	
}
void display(int q[],int *f, int *count)
{
	int i;
	if(*count==0)
		printf("Nothing to display");
	else
	{
		for(i=*f;i<=*count;i++);
		{
			printf("%d",q[*f]);
			((*f)++)%QSIZE;
		}
	}
}
