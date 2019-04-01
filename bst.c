#include<stdio.h>
#include<stdlib.h>

struct tnode
{
	int data;
	struct tnode *left;
	struct tnode *right;
}*root=NULL;

struct snode
{
	struct tnode *t;
	struct snode *next;
};

int stack[100],top=-1;

void inorder(struct tnode * );
void push(struct snode ** ,struct tnode * );
struct tnode *pop(struct snode ** );
void delete(struct tnode ** , int );
void height(struct tnode * );

int main()
{
	while(1)
	{
	int choice,n,m;
	printf("1.insert\n2.delete\n3.display\n4.height\n5.quit\n");
	printf("enter choice\n");	
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			printf("enter element : ");
			scanf("%d",&n);
			struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));
			temp->data=n;
			temp->left=NULL;
			temp->right=NULL;
			if(root==NULL)
			{	
				root=temp;			
			}
			else
			{
				struct tnode *ptr,*p;
				ptr=root;
				while(ptr!=NULL)
				{
					p=ptr;
					if(n>ptr->data)
						ptr=ptr->right;
					else if(n<ptr->data)
						ptr=ptr->left;
					else 
					{
						printf("duplicate value\n");
						break;
					}
				}
				if(n<p->data)
					p->left=temp;
				else
					p->right=temp;
				
			}
			break;
		case 2:
			printf("enter element to be deleted : \n");
			scanf("%d",&m);
			delete(&root,m);
			break;
		case 3:
			inorder(root);
			break;
		case 4:
			height(root);
			break;
		
		case 5:
			exit(0);
		default:
			printf("enter valid choice\n");	
	}
	}
	return 0;
}

void inorder(struct tnode *root)
{
	struct tnode *current;
	current=root;
	struct snode *s;
	s=NULL;
	if(current==NULL)
	{
		printf("tree empty\n");
		return ;
	}
	while(1)
	{
		if(current!=NULL)
		{
			push(&s,current);
			current=current->left;
		}
		else
		{
			if(s!=NULL)
			{
				//printf("inside\n");
				current=pop(&s);
				printf("%d\t",current->data);
				current=current->right;
			}
			else 
				break;
		}
	}
	printf("\n");
}

void height(struct tnode *root)
{
	int h1=0,h2=0;
	struct tnode *ptr=root;
	while(ptr->left!=NULL || ptr->right!=NULL)
	{
		h1++;
		if(ptr->left==NULL)
			ptr=ptr->right;
		else
			ptr=ptr->left;
	}	
	ptr=root;

	while(ptr->left!=NULL || ptr->right!=NULL)
	{
		h2++;
		if(ptr->right==NULL)
			ptr=ptr->left;
		else
			ptr=ptr->right;
	}
	if(h1>h2)
		printf("height : %d\n",h1);
	else
		printf("height : %d\n",h2);
}

void delete(struct tnode **root,int m)
{
	int flag=0;	
	struct tnode *temp=*root,*parent=*root;
	while(temp!=NULL)
	{
		if(m>temp->data)
		{	
			parent=temp;
			temp=temp->right;
		}
		else if(m<temp->data)
		{
			parent=temp;
			temp=temp->left;
		}
		else
		{
			flag=1;
			if(temp->left==NULL && temp->right==NULL)
			{
				printf("Deleting a leaf\n");
				if(parent->left==temp)
					parent->left=NULL;
				else if(parent->right==temp)
					parent->right=NULL;
				else 
				{
					(*root)->data=0;
					*root=NULL;
					//free(root);
					break;
				}
				free(temp);
			}

			else if(temp->left==NULL || temp->right==NULL)
			{
				printf("Deleting a node with one child\n");
				if(temp->right!=NULL)
				{
					struct tnode *temp2=temp->right;
					temp->data=temp2->data;
					temp->left=temp2->left;
					temp->right=temp2->right;
					free(temp2);		
				}
				else
				{
					struct tnode *temp2=temp->left;
					temp->data=temp2->data;
					temp->left=temp2->left;
					temp->right=temp2->right;
					free(temp2);
				}
			}
		
			else
			{
				printf("Deleting two child parent\n");
				struct tnode *temp2=temp->right,*p=temp;
				while(temp2->left!=NULL)
				{
					p=temp2;
					temp2=temp2->left;
				}
				if(p==temp)
				{
					temp->data=temp2->data;
					temp->right=temp2->right;
				}
				else
				{
					temp->data=temp2->data;
					p->left=NULL;							
				}
				free(temp2);
			}
			break;
		}
	}	
	if(flag==0)
		printf("element not in tree\n");

}

void push(struct snode **top,struct tnode *temp)
{
	struct snode *new=(struct snode *)malloc(sizeof(struct snode));
	new->t=temp;
	if(*top==NULL)
	{
		new->next=NULL;
		*top=new;
	}
	else
	{
		new->next=*top;
		*top=new;
	}
}

struct tnode *pop(struct snode **top)
{
	struct tnode *res;
	struct snode *temp;
	temp=*top;
	res=temp->t;
	*top=(*top)->next;
	free(temp);
	return res;
}	
