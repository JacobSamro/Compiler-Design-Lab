#include<stdio.h>

#include<conio.h>
struct stack
{
int no;
struct stack *next;
}
*start=NULL;
typedef struct stack st;
void push();
int pop();
void display();
void main()
{
char ch;
int choice,item;
do
{
clrscr();
printf("\n 1: push");
printf("\n 2: pop");
printf("\n 3: display");
printf("\n Enter your choice");
scanf("%d",&choice);
switch (choice)
{
case 1: push();
break;
case 2: item=pop();
printf("The delete element in %d",item);
break;
case 3: display();
break;
default : printf("\n Wrong choice");
};

printf("\n do you want to continue(Y/N)");
fflush(stdin);
scanf("%c",&ch);
}
while (ch=='Y'||ch=='y');
}
void push()
{
st *node;
node=(st *)malloc(sizeof(st));
printf("\n Enter the number to be insert");
scanf("%d",&node->no);
node->next=start;
start=node;
}
int pop()
{
st *temp;
temp=start;
if(start==NULL)
{
printf("stack is already empty");
getch();
exit();
}
else
{
start=start->next;
free(temp);
}
return(temp->no);
}
void display()
{

st *temp;
temp=start;
while(temp->next!=NULL)
{
printf("\nno=%d",temp->no);
temp=temp->next;
}
printf("\nno=%d",temp->no);
}
