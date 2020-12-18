#include<stdio.h>
#include<stdlib.h>
#define Max 5

int cnt=0;

struct Node
{
	int data;
	struct Node* next;	
}*front=NULL,*rear=NULL;

//-1
struct Node* create_new_node()
{
	return (struct Node*)calloc(1,sizeof(struct Node));
}

//0
void free_all()
{
	struct Node* ptr=front;
	while(ptr)
	{
		front=front->next;
		free(ptr);
		ptr=front;
	}
	
	front=rear=NULL;
}

//1
struct Node** push(int data)
{
	if(cnt==Max)
	{
		printf("\n\nERROR: Overflow.");
		return NULL;
	}
	
	struct Node* nd=create_new_node();
	
	if(!nd)
	{
		printf("\n\nERROR: Dynamic allocation failed.");
		return NULL;
	}
	
	if(rear)
	rear->next=nd;
	
	else
	front=nd;
	
	rear=nd;
	
	nd->data=data;
	nd->next=NULL;
	
	cnt++;
	
	return &rear;
}


//2
struct Node** pop(int* val)
{
	if(!front)
	{
		if(cnt>0)
		{
			printf("\n\nERROR: Underflow.");
			return NULL;
		}
		else
		{
			printf("\n\nERROR: The queue is empty.");
			return NULL;	
		}
	}
	
	struct Node* ptr=front;
	
	*val=ptr->data;
	
	front=front->next;
	free(ptr);
	
	if(!front)
	rear=front;
	
	return &front;
}

//3
struct Node** front_val(int* val)
{
	if(!front)
	{
		if(cnt>0)
		{
			printf("\n\nERROR: Underflow.");
			return NULL;
		}
		else
		{
			printf("\n\nERROR: The queue is empty.");
			return NULL;	
		}
	}
	
	*val=front->data;
	
	return &front;
}

//4
struct Node** back_val(int* val)
{
	if(!front)
	{
		if(cnt>0)
		{
			printf("\n\nERROR: Underflow.");
			return NULL;
		}
		else
		{
			printf("\n\nERROR: The queue is empty.");
			return NULL;	
		}
	}
	
	*val=rear->data;
	
	return &front;
}

//5
int size()
{
	if(!front)
	return 0;
	
	struct Node* ptr=front->next;
	int c=1;
	
	while(ptr)
	{
		c++;
		ptr=ptr->next;
	}
	
	return c;
}

//6
struct Node* empty()
{
	return front;
}

//7
struct Node** display()
{
	if(!front)
	{
		if(cnt>0)
		{
			printf("\n\nERROR: Underflow.");
			return NULL;
		}
		else
		{
			printf("\n\nERROR: The queue is empty.");
			return NULL;	
		}
	}
	
	struct Node* ptr=front;
	
	printf("\n\n");
	
	while(ptr)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	
	return &front;
}

void menu()
{
	printf(" MENU:\n-------\n");
	printf("\n1) Push.");
	printf("\n2) Pop.");
	printf("\n3) Front.");
	printf("\n4) Back.");	
	printf("\n5) Size.");
	printf("\n6) Empty.");
	printf("\n7) Display.");
	printf("\n8) Re-display the menu.");
	printf("\n0) Exit.");
}

int main()
{
	
	menu();
	
	printf("\n\n");
	int i,ch,val;
	for(i=0;i<130;i++)
	putchar('-');
	printf("\n\nEnter choice: ");
	scanf("%d",&ch);
	printf("\n");
	for(i=0;i<130;i++)
	putchar('-');
	
	while(ch)
	{
		switch(ch)
		{
			case 1:		printf("\n\nEnter the value to be pushed: ");
						scanf("%d",&val);
						if(push(val))
						printf("\n\nMessage: Successfully pushed the value '%d' inside the queue.",val);
						break;
			
			case 2: 	if(pop(&val))						
						printf("\n\nMessage: The item successfully popped out of the queue is: %d",val);
						break;
			
			case 3:		if(front_val(&val))
						printf("\n\nMessage: The item pointed by the front in the queue is: '%d'",val);
						break;
			
			case 4:		if(back_val(&val))
						printf("\n\nMessage: The item pointed by the rear in the queue is: '%d'",val);
						break;
			
			case 5:		printf("\n\nMessage: The number of elements present in the queue is: '%d'",size());
						break;
						
			case 6:		if(!empty())
						{
							if(cnt>0)
							printf("\n\nMessage: Underflow.");
							else
							printf("\n\nMessage: The queue is empty.");
						}
						else
						printf("\n\nMessage: The queue is not empty.");
						break;
			
			case 7:		printf("\n\nMessage: Displaying the whole queue.");
						if(display())
						printf("\n\nMessage: Successfully displayed the whole queue.");
						break;
				
			case 8:		printf("\n\nMessage: Re-displaying the menu.\n\n");
						menu();
						break;
			
			default:	printf("\n\nError: Wrong choice.");
						break;
		};
		
		printf("\n\n");
		for(i=0;i<130;i++)
		putchar('-');
		printf("\n\nEnter choice: ");
		scanf("%d",&ch);
		printf("\n");
		for(i=0;i<130;i++)
		putchar('-');
	}
	
	free_all();
	
	printf("\n\nMessage: Program successfully exited.");
	
	printf("\n\n");
	for(i=0;i<130;i++)
	putchar('-');
	printf("\n\n");
}
