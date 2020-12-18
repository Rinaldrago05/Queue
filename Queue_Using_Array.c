#include<stdio.h>
#include<stdlib.h>
#define Max 5
int cnt=0; 

struct Queue
{
	int rear;
	int front;
	int* arr;
}*s=NULL;

struct Queue* initialise_structure()
{
	s=(struct Queue*)calloc(1,sizeof(struct Queue));
	s->rear=s->front=-1;
	
	return s;
}

int* initialise_array()
{
	s->front=0;
	return s->arr=(int*)calloc(1,sizeof(int));
}

int* reallocate(int val)
{
	return (s->arr=(int*)realloc(s->arr,((s->rear+val)*sizeof(int))));
}

//1
struct Queue* push(int val)
{
	if(cnt==Max)
	{
		printf("\n\nError: Overflow.");
		return NULL;
	}
	
	if(s->rear==-1 && !initialise_array())
	{
		printf("\n\nError: Dynamic allocation failed.");
		return NULL;	
	}
		
	if(s->rear!=-1 && !reallocate(2))
	{
		printf("\n\nError: Dynamic allocation failed.");
		return NULL;
	}
	
	cnt++;
	s->rear++;
	s->arr[s->rear]=val;
	
	return s;
	
}

//2
struct Queue* pop(int* val)
{
	if(s->rear==-1)
	{
		if(cnt>0)
		{
			printf("\n\nError: Underflow");
			return NULL;
		}
		
		if(s->front==-1)
		{
			printf("\n\nError: The queue is empty.");
			return NULL;
		}
	}	
	
	int i;
	
	*val=s->arr[s->front];
	
	for(i=0;i<s->rear;i++)
	s->arr[i]=s->arr[i+1];
	
	if(!reallocate(0))
	{
		printf("\n\nError: Dynamic allocation failed.");
		return NULL;
	}
	
	s->rear--;
	
	if(s->rear==-1)
	{
		free(s->arr);
		s->front--;
		s->arr=NULL;
	}
	
	return s;
}

//3
struct Queue* front(int* val)
{
	if(s->rear==-1)
	{
		if(cnt>0)
		{
			printf("\n\nError: Underflow");
			return NULL;
		}
		
		if(s->front==-1)
		{
			printf("\n\nError: The queue is empty.");
			return NULL;
		}
	}
	
	*val=s->arr[s->front];
	
	return s;
}

//4
struct Queue* back(int* val)
{
	if(s->rear==-1)
	{
		if(cnt>0)
		{
			printf("\n\nError: Underflow");
			return NULL;
		}
		
		if(s->front==-1)
		{
			printf("\n\nError: The queue is empty.");
			return NULL;
		}
	}
	
	*val=s->arr[s->rear];
	
	return s;
}

//5
int size()
{	
	if(s->rear==-1)
	printf("\n\nError: The queue is empty.");
	
	return (s->rear)+1;	
} 

//6
int* empty()
{
	return s->arr;
}

//7
struct Queue* display()
{
	if(s->rear==-1)
	{
		if(cnt>0)
		{
			printf("\n\nError: Underflow");
			return NULL;
		}
		
		if(s->front==-1)
		{
			printf("\n\nError: The queue is empty.");
			return NULL;
		}
	}
	
	int i;
	printf("\n\n");
	for(i=s->front;i<=s->rear;i++)
	printf("%d ",s->arr[i]);
	
	return s;
}

void free_all()
{
	if(s->arr)
	free(s->arr);
	
	free(s);
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
	if(!(initialise_structure()))
	{
		printf("\n\nError: Dynamic allocation failed.");
		return 0;
	}
	
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
			
			case 3:		if(front(&val))
						printf("\n\nMessage: The item pointed by the front in the queue is: '%d'",val);
						break;
						
			case 4:		if(back(&val))
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
