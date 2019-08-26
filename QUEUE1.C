#include<stdio.h>
#include<conio.h>
#define QSIZE 20

void enqueue(int *,int *);
void dequeue(int *,int *,int *);
void display(int *, int *, int *);

void main()
{
	int q[QSIZE],r=-1,f=0;
	int choice2;
	char choice1='y';
	clrscr();
	while(choice1=='y'||choice1=='Y')
	{
		printf("\n Enter choice of operation on queue: 1.ENQUEUE 2.DEQUEUE 3.DISPLAY:\n");
		scanf("%d",&choice2);
		if(choice2==1)
		{
			enqueue(q,&r);
			display(q,&f,&r);
		}
		else if(choice2==2)
		{
			dequeue(q,&f,&r);
			display(q,&f,&r);
		}
		else if(choice2==3)
		{
			display(q,&f,&r);
		}
		else
		printf("\n Wrong input");
		printf("\n WANT TO CONTINUE? yes/no:enter y for yes and n for no:\t");
		fflush(stdin);
		scanf("%s",&choice1);
	}
	getch();
}
void enqueue(int q[],int *r)
{
	int item;
	printf("Enter item \n");
	scanf("%d",&item);
	if((*r==QSIZE-1))
		printf("\n Q is full");
	
		*r=*r+1;
		q[*r]=item;
	
	printf("Value inserted=%d",item);
}
void dequeue(int q[],int *f, int *r)
{
	if(*f>*r);
	{
		printf("Queue is empty\n");
	}
	printf("Elememt deleted is %d",q[*f]);
	(*f)++;	
}
void display(int q[],int *f, int *r)
{
	int i;
	if(*f>*r)
	printf("Nothing to display");
	for(i=*f;i<=*r;i++);
	{
		printf("%d",q[i]);
	}
}
