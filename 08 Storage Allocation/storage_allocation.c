#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct Heap
{
int data;
struct Heap *next;
}node;
node *create();
void main()
{
int choice, val;
char ans;
node *head;
void display(node *);
node *search(node *,int);
node *insert(node *);
void dele(node **);
head=NULL;
do

{
clrscr();
printf("\n Program to perform various operations on heap using dynamic memory
 management");
printf ("\n1.Create");
printf ("\n2.Display");
printf ("\n3.Insert an element in a list");
printf ("\n4.Delete an element from list");
printf ("\n5.Quit");
printf ("\n Enter Your Choice(1-5)");
scanf("%d",&choice);
switch(choice)
{
case 1:head=create();
break;
case 2:display(head);
break;
case 3:head=insert(head);
break;
case 4:dele(&head);
break;
case 5:exit(0);
default:clrscr();
printf("Invalid Choice,Try again");
getch();
}
}
while(choice!=5);
}
node *create()
{
node *temp,*new1,*head;
int val,flag;
char ans='y';
node *get_node();
temp=NULL;
flag=TRUE;
do
{
printf("\n Enter the Element");
scanf("%d",&val);
/*allocate new node*/
new1=get_node();
if(new1==NULL)
printf("\n Memory is not allocated");
new1-> data=val;
if (flag==TRUE)/* Executed only for the first time*/
{
head=new1;
temp=head; /*head is the first node in the heap*/

flag=FALSE;
}
else
{
temp->next=new1;
temp=new1;
}
printf("\nDo you want to enter more elements?(y/n)");
ans=getch();
}
while(ans=='y');
printf("\nThe list is created");
getch();
clrscr();
return head;
}
node *get_node()
{
node *temp;
temp=(node*)malloc(sizeof(node));
//using the mem. Allocation function
temp->next=NULL;
return temp;
}
void display(node*head)
{
node *temp;
temp=head;
if(temp==NULL)
{
printf("\n The list is empty\n");
getch();
clrscr();
return;
}
while(temp!= NULL)
{
printf("%d->",temp-> data);
temp=temp->next;
}
printf("NULL");
getch();
clrscr();
}
node *search(node *head,int key)
{
node *temp;
int found;
temp=head;
if (temp==NULL)

{
printf("The linked list is empty\n");
getch();
clrscr();
return NULL;
}
found=FALSE;
while(temp!=NULL&&found==FALSE)
{
if(temp->data != key)
temp = temp->next;
else
found=TRUE;
}
if(found == TRUE)
{
printf("\n The Elements is present in the list\n");
getch();
return temp;
}
else
printf("\n The Element is not present in the list\n");
getch();
return NULL;
}
node *insert(node *head)
{
int choice;
node *insert_head(node*);
void insert_after(node*);
void insert_last(node*);
printf("\n 1.Insert a node as a head node");
printf("\n 1.Insert a node as a last node");
printf("\n 1.Insert a node as at the intermediate position in the list ");
printf("\n 1.Enter your choice for insertion of node ");
scanf("%d",&choice);
switch(choice)
{
case 1:head = insert_head(head);
break;
case 2:insert_last(head);
break;
case 3:insert_after (head);
break;
}
return head;
}
node *insert_head(node*head)
{
node *New,*temp;

New=get_node();
printf ("\n Enter the element which you want to insert ");
scanf("%d",&New->data);
if(head == NULL)
head = New;
else
{
temp=head;
New->next = temp;
head= New;
}
return head;
}
void insert_last(node *head)
{
node *New,*temp;
New = get_node();
printf ("\n Enter the element which you want to insert ");
scanf("%d",&New->data);
if(head == NULL)
{
head = New;
}
else
{
temp=head;
while(temp->next!=NULL)
temp=temp->next;
temp->next=New;
New->next=NULL;
}
}
void insert_after(node *head)
{
int key;
node *New,*temp;
New = get_node();
printf("Enter the element after which you want to insert ");
scanf("%d",&key);
temp=head;
do
{
if(temp->data==key)
{
printf ("Enter element which you want to insert ");
scanf("%d",&New->data);
New->next=temp->next;
temp->next=New;
return;
}

else
temp=temp->next;
}
while(temp!=NULL);
}
node *get_prev(node *head,int val)
{
node *temp,*prev;
int flag;
temp = head;
if(temp == NULL)
return NULL;
flag=FALSE;
prev=NULL;
while(temp!=NULL && !flag)
{
if(temp->data!=val)
{
prev = temp;
temp = temp->next;
}
else
flag = TRUE;
}
if(flag) /*if Flag is true*/
return prev;
else
return NULL;
}
void dele(node **head)
{
int key;
node *New,*temp,*prev;
temp=*head;
if (temp== NULL)
{
printf ("\n The list is empty\n ");
getch();
clrscr();
return;
}
clrscr();
printf("\nENTER the Element you want to delete:");
scanf("%d",&key);
temp=search(*head,key);
if(temp!=NULL)
{
prev=get_prev(*head,key);
if(prev!=NULL)
{

prev ->next = temp-> next;
free(temp);
}
else
{
*head = temp->next;
free(temp); // using the mem. Dellocation function
}
printf("\n The Element is deleted\n");
getch();
clrscr();
}
}
