#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
struct node *root=NULL;
void insert_at_beginning(int x);
void insert_at_end(int x);
void insert_at_position(int x,int pos);
void delete_at_beginning();
void delete_at_end();
void delete_at_position(int pos);
void traverse();
	
void insert_at_beginning(int x)
{
	struct node *p;
	p=(struct node *)malloc(sizeof(struct node));
   	p->data=x;
                	if(root==NULL)
	            {
		            root=p;
		            p->next=NULL;
	            }
	            else
	            {
		            p->next=root;
		            root=p;
	            }
	            printf("\n element inserted\n");
                }

void insert_at_end(int x)
{
	struct node *p,*temp;
	p=(struct node *)malloc(sizeof(struct node));
	p->data=x;
	p->next=NULL;
	if(root==NULL)
	{
		root=p;
	}
	else
	{
		temp=root;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=p;
	}
	printf("\nelement inserted\n");
}

void insert_at_position(int x,int pos)
{
	struct node *p,*temp;
	int i;
	temp=root;
	for(i=1;i<pos-1;i++)
	{
		if(temp==NULL)
		{
			printf("\n insufficient elements available\n");
			getch();
			return;
		}
			temp=temp->next;
	}
	p=(struct node *)malloc(sizeof(struct node));
	p->data=x;
	p->next=temp->next;
	temp->next=p;
	printf("\n element inserted\n");
}

void deletion_at_beginning()
{
	struct node *temp;
	if(root==NULL)
	{
	printf("\ninsufficient element");
	}
	else
	{
	printf("\n deleted element = %d\n",root->data);
	temp=root;
	if(root->next==NULL)
		{
			root=NULL;
			free(temp);
		}
		else
		{
			root=root->next;
			free(temp);
		}
}
}

void deletion_at_end()
{
	struct node *temp,*t;
	if (root==NULL)
	{
		printf("\nlist is empty not possible\n");
	}
	else
	{
		temp=root;
		if(root->next==NULL)
		{
			printf("\ndeleted element = %d\n",root->data);
			root=NULL;
			free(temp);
		}
		else
		{
			t=root->next;
			while(t->next!=NULL)
			{
				t=t->next;
			}
			printf("\ndeleted element = %d\n",t->data);
			temp->next=NULL;
			free(t);
		}
	}
}

void deletion_at_position(int pos)
{
	struct node *p,*temp;
	int i;
	temp=root;
	for(i=1;i<pos-1;i++)
	{
		if(temp==NULL)
		{
			printf("\ninsufficient elements\n");
			getch(); return;
		}
		temp=temp->next;
	}
	p=temp->next;
	printf("\ndeleted element = %d\n",p->data);
	temp->next=p->next;
	free(p);
}

void traverse()
{
	struct node *temp;
	temp=root;
	if(root==NULL)
	printf("\nlinked list is empty\n");
	else
	{
		printf("\nelements in linked list = ");
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}
int main()
{
	int x,ch,pos;
	do
	{
		printf("\nenter 1 for insertion at beginning");
		printf("\nenter 2 for insertion at end");
		printf("\nenter 3 for insertion at position");
		printf("\nenter 4 for deletion at beginning");
		printf("\nenter 5 for deletion at end");
		printf("\nenter 6 for deletion at position");
		printf("\nenter 7 for traversing\n");
		int z;
		for(z=1;z<25;z++)
		{
		printf("*");
		}
		printf("\nenter 8 for exit");
		printf("\nenter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\n enter x\n");
				scanf("%d",&x);
			    insert_at_beginning(x);
				break;
			case 2:
				printf("\n enter x\n");
				scanf("%d",&x);
				insert_at_end(x);
				break;
			case 3:
				printf("\n enter x and position\n");
				scanf("%d%d",&x,&pos);
				insert_at_position(x,pos);
				break;
			case 4:
				deletion_at_beginning();
				break;
			case 5:
				deletion_at_end();
				break;
			case 6:
				printf("\n enter position\n");
				scanf("%d",&pos);
			    deletion_at_position(pos);
				break;
			case 7:
				traverse();
				break;
			case 8:
				exit(0);
			default:
				printf("\n enter correct choice\n");
				break;
		}
	}while(1);
	return 0;
}


