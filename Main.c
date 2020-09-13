/*  Singly circular linked list */

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    
};

typedef struct Node NODE;
typedef struct Node * PNODE;
typedef struct Node ** PPNODE;

void InsertLast(PPNODE Head, PPNODE Tail, int value)
{
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));
    
    newn->data = value;
    newn->next = NULL;
    
    
    if((*Head ==NULL) && (*Tail == NULL))       // Linked list is empty
    {
        *Head = newn;
        *Tail = newn;
    }
    else            // Linked list contains atleast one node
    {
        (*Tail)->next = newn;
        *Tail = (*Tail) ->next;   //  *Tail = newn;
    }
    (*Tail)->next = *Head;
    
}

void InsertFirst(PPNODE Head, PPNODE Tail, int value)
{
    PNODE newn = NULL;
    
    newn = (PNODE)malloc(sizeof(NODE));
    
    newn->data = value;
    newn->next = NULL;
    
    
    if((*Head ==NULL) && (*Tail == NULL))       // Linked list is empty
    {
        *Head = newn;
        *Tail = newn;
    }
    else            // Linked list contains atleast one node
    {
        newn->next = *Head;
       
        *Head = newn;
    }
    (*Tail)->next = *Head;
    
}


void Display(PNODE Head, PNODE Tail) 
{
	if((Head == NULL) && (Tail == NULL))  
	{
		return;  
	}
	
	do
	{
		printf("%d  <=> ",Head->data);   
		Head = Head -> next;  
	}while(Head != Tail -> next); 
	
	printf("\n");
}


int Count(PNODE Head, PNODE Tail) 
{
	int cnt=0;
	if((Head == NULL) && (Tail == NULL))  
	{
		return 0;  
	}
	
	do 
	{
		cnt++;  
		Head = Head -> next;  
	}while(Head != Tail -> next);
	
	return cnt;
	
}

void DeleteFirst(PPNODE Head,PPNODE Tail)
{
	if((*Head==NULL) && (*Tail==NULL))
	{
		return;
	}
	else if(*Head==*Tail)
	{
		free(*Head);
		*Head=NULL;
		*Tail=NULL;
	}
	else
	{
		*Head=(*Head)->next;
		free((*Tail)->next);
		
		(*Tail)->next=*Head;
		
	}
}

void DeleteLast(PPNODE Head, PPNODE Tail)
{
	PNODE temp=*Head;
	PNODE temp2=NULL;
	
	if((*Head==NULL) && (*Tail==NULL))
	{
		return;
	}
	else if(*Head==*Tail)
	{
		free(*Head);
		*Head=NULL;
		*Tail=NULL;
	}
	else
	{
		while(temp->next->next!=(*Tail)->next)
		{
			temp=temp->next;
		}
		
		temp2=temp->next;
		*Tail=temp;
		free(temp2);
		(*Tail)->next=*Head;
	}
	
}

void InsertAtPos(PPNODE Head, PPNODE Tail, int no, int pos)
{
	int size=0, i=0;
	PNODE temp=*Head;
	PNODE newn=NULL;
	
	newn=(PNODE)malloc(sizeof(NODE));
	newn->data=no;
	newn->next=NULL;
	
	size = Count(*Head,*Tail);
	
	if(pos<0)
	{
		return;
	}
	else if(pos==1)
	{
		InsertFirst(Head,Tail,no);
	}
	else if(pos==size+1)
	{
		InsertLast(Head,Tail,no);
	}
	else
	{
		for(i=1 ; i<pos-1 ; i++)
		{
			temp=temp->next;
		}
		
		newn->next=temp->next;
		temp->next=newn;
		(*Tail)->next=*Head;
		
	}
}


void DeleteAtPos(PPNODE Head, PPNODE Tail, int pos)
{
	int size=0, i=0;
	PNODE temp=*Head;
	PNODE temp2=NULL;
	
	size=Count(*Head,*Tail);
	
	if(pos<0)
	{
		return;
	}
	else if(pos==1)
	{
		DeleteFirst(Head,Tail);
	}
	else if(pos==size+1)
	{
		DeleteLast(Head,Tail);
	}
	else
	{
		for(i=1 ; i<pos-1 ; i++)
		{
			temp=temp->next;
		}
		
		temp2=temp->next;
		temp->next=temp->next->next;
		free(temp2);
		
	}
}




int main()
{
    PNODE first = NULL;
    PNODE last = NULL;          // Nawin
    int no = 0, iRet=0;
    
	printf("\n---------------------------InsertFirst---------------------------\n");
	
    printf("Enter number : ");
    scanf("%d",&no);
    InsertFirst(&first,&last,no);
	printf("Enter number : ");
    scanf("%d",&no);
    InsertFirst(&first,&last,no);
	printf("Enter number : ");
    scanf("%d",&no);
    InsertFirst(&first,&last,no);
	
	Display(first,last);
	
	printf("\n------------------------------Count------------------------------\n");
	
	iRet=Count(first,last);
	printf("\nNumber of elements are : %d \n",iRet);
	
	printf("\n---------------------------InsertLast---------------------------\n");
	
    printf("Enter number : ");
    scanf("%d",&no);
    InsertLast(&first,&last,no);
	printf("Enter number : ");
    scanf("%d",&no);
    InsertLast(&first,&last,no);
	printf("Enter number : ");
    scanf("%d",&no);
    InsertLast(&first,&last,no);
	
	Display(first,last);
	
	printf("\n------------------------------Count------------------------------\n");
	
	iRet=Count(first,last);
	printf("\nNumber of elements are : %d \n",iRet);
	
	printf("\n---------------------------DeleteFirst---------------------------\n");
	
	DeleteFirst(&first,&last);
	Display(first,last);
	
	printf("\n------------------------------Count------------------------------\n");
	
	iRet=Count(first,last);
	printf("\nNumber of elements are : %d \n",iRet);
	
	printf("\n---------------------------DeleteLast---------------------------\n");
	
	DeleteLast(&first,&last);
	Display(first,last);
	
	printf("\n------------------------------Count------------------------------\n");
	
	iRet=Count(first,last);
	printf("\nNumber of elements are : %d \n",iRet);
	
	printf("\n---------------------------InsertAtPos---------------------------\n");
	
    printf("Enter number : ");
    scanf("%d",&no);
    InsertAtPos(&first,&last,no,1);
	
	Display(first,last);
	
	printf("\n------------------------------Count------------------------------\n");
	
	iRet=Count(first,last);
	printf("\nNumber of elements are : %d \n",iRet);
	
	printf("\n---------------------------InsertAtPos---------------------------\n");
	
    printf("Enter number : ");
    scanf("%d",&no);
    InsertAtPos(&first,&last,no,3);
	
	Display(first,last);
	
	printf("\n------------------------------Count------------------------------\n");
	
	iRet=Count(first,last);
	printf("\nNumber of elements are : %d \n",iRet);
	
	printf("\n---------------------------DeleteAtPos---------------------------\n");
	
    DeleteAtPos(&first,&last,5);
	
	Display(first,last);
	
	printf("\n------------------------------Count------------------------------\n");
	
	iRet=Count(first,last);
	printf("\nNumber of elements are : %d \n",iRet);
	
	printf("\n---------------------------DeleteAtPos---------------------------\n");
	
    DeleteAtPos(&first,&last,1);
	
	Display(first,last);
	
	printf("\n------------------------------Count------------------------------\n");
	
	iRet=Count(first,last);
	printf("\nNumber of elements are : %d \n",iRet);
	
	
    
    printf("\n-----------------------------------------------------------------\n");
    return 0;
}
