#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
	};
	
typedef struct node* node;

node get_node();

node ins_front(node first, int val);

void compare(node first, node second);

void display(node first);

node first = NULL;
node second = NULL;

int main(){
	int i, x, y, val1, val2;
	char ch1 = 'y',ch2 = 'y',ch3,ch4;
	printf("Enter values for first linked list from the front: \n");
	while(ch1 == 'Y' || ch1 == 'y'){
		
			
			printf("Enter value from front: ");
			scanf("%d", &val1);
			first = ins_front(first, val1);
			printf("\n Do you wish to enter more values|Enter y/Y for yes");
			scanf("%c",&ch1);	
            
			
		}
	printf("Enter values for second linked list from the front: \n");
	while(ch2 == 'Y' || ch2 == 'y'){
		
				printf("Enter value from front: ");
				scanf("%d", &val2);
				second = ins_front(second, val2);
				printf("\n Do you wish to enter more values|Enter y/Y for yes");
			        scanf("%c",&ch2);	
            
				
		}
	printf("Do you wish to display your linked lists? Enter Y/y for yes and N/n for no ");
	scanf("%c",&ch3);
	if(ch3 == 'Y' || ch3 == 'y')
	{
		printf("Which list do you want to display:1.FIRST LIST 2.SECOND LIST 3.BOTH ");
		scanf("%d",&x);
		switch(x)
		{
			case 1: display(first);
				break;
			case 2: display(second);
				break; 
			case 3: display(first);
				printf("\n");
				display(second);
				break;
			default: printf("INVALID CHOICE\n");
		}
	}
	printf("Do you wish to compare your linked lists? Enter Y/y for yes and N/n for no ");
	scanf("%c",&ch4);
	if(ch4 == 'Y' || ch4 == 'y')
		compare(first,second);
	}
	
		
node get_node(){
	node temp;
	temp = (node)malloc(sizeof(struct node));
	temp->next = NULL;
	return temp;
	}
	
	
node ins_front(node first, int val){
	node temp;
	if(first == NULL){
		first = get_node();
		first->val = val;
		}
	else{
		temp = get_node();
		temp->val = val;
		temp->next = first;
		first = temp;
		
		}
	return first;	
	}


void display(node first){
	node curr;
	curr = first;
	while(curr != NULL){
		printf("%d ", curr->val);
		curr = curr->next;
		}
	}

void compare(node first, node second)
{
	int count1 = 0 , count2 = 0, flag = 0;
	node curr1 = first, curr2 = second;
	while (curr1->next != NULL)
	{
		count1++;
		curr1 = curr1->next;
	}
	while (curr2->next != NULL)
	{
		count2++;
		curr2 = curr2->next;
	}
	if(count1 != count2)
	{
		printf("Lists are not equal\n");
	}
	else
	{
		curr1 = first;
		curr2 = second;
		while(curr1->next != NULL)
		{ 
			if(curr1->val != curr2->val)
			{
				flag = 1;
				break;
			}
			else
			{
				curr1 = curr1->next;
				curr2 = curr2->next;
			}
		}
		if(flag == 1)
		{
			printf("Lists are not equal\n");
		}
		else
		{
			printf("Lists are equal");
		}
	}
}
