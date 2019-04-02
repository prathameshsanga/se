#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
}*head=NULL;

void josephus(int , int );

int main()
{
	int n,k;
	printf("enter n value : ");
	scanf("%d",&n);
	printf("enter k value : ");
	scanf("%d",&k);
	josephus(n,k);
	//printf("%d\n",josephus(n,k));
	return 0;
}

void josephus(int n,int k)
{
	int i=1;
	struct node *cur;
	while(i<=n)
	{
		struct node *new = (struct node *)malloc(sizeof(struct node));
		new->data=i;
		new->next=NULL;
		if(head==NULL)
		{
			//printf("if\n");
			head=new;
			cur=head;
		}
		else
		{
			//printf("else\n");
			cur->next=new;
			cur=cur->next;
		}
		i++;
	}
	cur->next=head;
	i=1;
	struct node *temp=head;
	while(i<=n)
	{
		printf("%d\t",temp->data);
		temp=temp->next;	
		i++;
	}
	printf("\n");
	struct node *ptr2=head,*ptr1=head,*t;
	while(ptr1->next!=ptr1)
	{
		int count=1;
		while(count!=k)
		{
			ptr2 = ptr1; 
           		ptr1 = ptr1->next; 
            		count++; 
		}
		t=ptr1;
		ptr2->next = ptr1->next; 
        	ptr1 = ptr2->next;
		free(t);	
	}
	printf("%d\n",ptr1->data);	
}
