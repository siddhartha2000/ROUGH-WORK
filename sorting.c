#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
	};
	
typedef struct node* node;

node get_node();


node ins_front(node first, int val);
void bubble_sort(node first);
void display(node first);
node reverse(node first);

node first = NULL;

int main(){
	int i, x, val;
	x=0;
	while(x != 5){
		printf("\n1: Enter value from front\n");
        printf("2: Display\n");
        printf("3: sorting\n");
		printf("4: reversing\n");


		scanf("%d", &x);
			switch(x){
			case 1:
				printf("Enter value from front: ");
				scanf("%d", &val);
				first = ins_front(first, val);
				break;
            
            case 2:
				display(first);
				break;
            case 3:
				printf("The linked list before sorting ");
				display(first);
                printf("The linked list after sorting ");
                bubble_sort(first);
                display(first);
				break;
				
			case 4:
				printf("The linked list before reversal ");
				display(first);
                printf("The linked list after reversal ");
                reverse(first);
                display(first);
				break;
			}
		}
	
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
		first-> val = val;
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

void bubble_sort(node first)
{
    node second;
    int temp;
    second = first->next;
    if(first == NULL)
        printf("List is empty");
    while(second->next!=NULL)
    {
        if(first->val > second->val)
        {
            temp = first->val;
            first->val = second->val;
            second->val = temp;
        }

        first = second;
        second = second->next;
    }
}

node reverse(node first)
{
    node prev , curr , temp;
    prev = NULL;
    curr = first;
    while( curr != NULL)
    {
        temp = curr->next;
        temp->next = curr;
        prev = curr;
        curr = curr->next;
    }
    first->next = NULL;
    first = prev;
}