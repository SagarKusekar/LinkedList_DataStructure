/*      Doubly Linear linked list */

#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node * prev;
    int data;
    struct Node * next;
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

////////////////////////////////////////////////////////////////////////////////



//             InsertFirst



////////////////////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE Head, int no)
{
	PNODE newn=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=no;
	newn->prev=NULL;
	newn->next=NULL;
	
	if(*Head==NULL)
	{
		*Head=newn;
	}
	else
	{
		
		newn->next=*Head;
		(*Head)->prev=newn;
		*Head=newn;
	}
}

////////////////////////////////////////////////////////////////////////////////



//             Display



////////////////////////////////////////////////////////////////////////////////
void Display(PNODE Head)
{
	printf("\n");
	while(Head!=NULL)
	{
		printf(" %d <=> ",Head->data);
		Head=Head->next;
	}
	
	printf("NULL \n");
}

////////////////////////////////////////////////////////////////////////////////



//             Count



////////////////////////////////////////////////////////////////////////////////
int Count(PNODE Head)					// int Count(struct Node * Head)
{
	int cnt=0;
	
	while(Head!=NULL)
	{
		cnt++;
		Head=Head->next;
	}
	
	return cnt;
}

////////////////////////////////////////////////////////////////////////////////



//             InsertLast



////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE Head, int no)			//  void InsertLast(struct Node ** Head, int no)
{
	PNODE temp=NULL;							//  struct Node * temp = NULL;
	PNODE newn=*Head;							//  struct Node * newn = *Head;
	newn=(PNODE)malloc(sizeof(NODE));			//  newn = (struct Node *)malloc(sizeof(struct node));
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	
	if(*Head==NULL)
	{
		*Head=newn;
	}
	else
	{
		temp=*Head;
		
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		
		temp->next=newn;
		newn->prev=temp;
	}
}


////////////////////////////////////////////////////////////////////////////////



//             DeleteFirst



////////////////////////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE Head)
{
	if(*Head==NULL)									// empty LL
	{
		return;
	}
	else if((*Head)->next == NULL)					// single node
	{
		free(*Head);
		*Head=NULL;
	}
	else											//  multiple nodes 
	{
		*Head=(*Head)->next;
		free((*Head)->prev);
		(*Head)->prev=NULL;
	}
}

////////////////////////////////////////////////////////////////////////////////



//             DeleteLast



////////////////////////////////////////////////////////////////////////////////
void DeleteLast(PPNODE Head)
{
	PNODE temp=*Head;
	
	if(*Head==NULL)
	{
		return;
	}
	else if((*Head)->next == NULL)
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp=temp->prev;
		free(temp->next);
		temp->next=NULL;	
	}
}

////////////////////////////////////////////////////////////////////////////////



//             InsertAtPos



////////////////////////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE Head, int no, int pos)
{
	int size=0,i=0;
	PNODE temp=*Head;
	PNODE newn=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	size=Count(*Head);
	
	if(pos<1 || pos>size+1)
	{
		return;
	}
	if(pos==1)
	{
		InsertFirst(Head,no);
	}
	else if(pos==size+1)
	{
		InsertLast(Head,no);
	}
	else
	{
		for(i=1 ; i<pos-1 ; i++)
		{
			temp=temp->next;
		}
		
		newn->next=temp->next;
		temp->next->prev=newn;
		
		temp->next=newn;
		newn->prev=temp;
	}	
}

////////////////////////////////////////////////////////////////////////////////



//             DeleteAtPos



////////////////////////////////////////////////////////////////////////////////
void DeleteAtPos(PPNODE Head, int pos)
{
	PNODE temp=*Head;
	
	int size=0, i=0;
	
	size=Count(*Head);
	
	if(pos<1  ||  pos>size+1)
	{
		return;
	}
	else if(pos==1)
	{
		DeleteFirst(Head);
	}
	else if(pos==size)
	{
		DeleteLast(Head);
	}
	else
	{
		for(i=1 ; i<pos-1 ; i++)
		{
			temp=temp->next;
		}
		
		temp->next=temp->next->next;
		free(temp->next->prev);
		
		temp->next->prev=temp;
	}
}


////////////////////////////////////////////////////////////////////////////////



//             Display Linked list in Reverse order



////////////////////////////////////////////////////////////////////////////////

void DisplayX(PNODE Head)
{
	printf("\n Reversed linked list is :   \n");
	
	if(Head==NULL)
	{
		return;
	}
	
	while(Head->next!=NULL)
	{
		Head=Head->next;
	}
	
	while(Head!=NULL)
	{
		printf(" %d  <=>",Head->data);
		Head=Head->prev;
	}
	printf("NULL \n");
}


int main()
{
	PNODE first = NULL;
	int no=0;
	int iRet=0;
	
	printf("\n-----------------InsertFirst-----------------------\n\n");
	printf("Insert Number : ");
	scanf("%d",&no);
	InsertFirst(&first,no);
	printf("Insert Number : ");
	scanf("%d",&no);
	InsertFirst(&first,no);
	printf("Insert Number : ");
	scanf("%d",&no);
	InsertFirst(&first,no);
	
	Display(first);
	
	DisplayX(first);  			// Reverse linked list
	
	printf("\n-----------------Count-----------------------\n\n");
	
	iRet=Count(first);
	printf(" number of nodes are : %d \n",iRet);
	
	printf("\n-----------------InsertLast-----------------------\n\n");
	
	printf("Insert Number : ");
	scanf("%d",&no);
	InsertLast(&first,no);
	printf("Insert Number : ");
	scanf("%d",&no);
	InsertLast(&first,no);
	
	Display(first);
	
	printf("\n-----------------Count-----------------------\n\n");
	
	iRet=Count(first);
	printf(" number of nodes are : %d \n",iRet);
	
	printf("\n-----------------DeleteFirst-----------------------\n\n");
	
	DeleteFirst(&first);
	Display(first);
	
	printf("\n-----------------DeleteLast-----------------------\n\n");
	
	DeleteLast(&first);
	Display(first);
	
	printf("\n-----------------InsertAtPos-----------------------\n\n");
	
	printf("Insert Number : ");
	scanf("%d",&no);
	InsertAtPos(&first,no,2);
	
	Display(first);
	
	printf("Insert Number : ");
	scanf("%d",&no);
	InsertAtPos(&first,no,2);
	
	Display(first);
	
	printf("\n-----------------DeleteAtPos-----------------------\n\n");
	
	DeleteAtPos(&first,2);
	Display(first);
	
	
	
	printf("\n------------------------------------------------\n");
	return 0;
}