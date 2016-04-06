#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define size 20
typedef struct node
{
char data;
struct node *left;
struct node *right;
}btree;
btree *stack[size];
int top;
void main()
{
btree *root;
char exp[80];
btree *create(char exp[80]);
void dag(btree *root);
clrscr();
printf("\nEnter the postfix expression:\n");
scanf("%s",exp);
top=-1;
root=create(exp);
printf("\nThe tree is created.....\n");
printf("\nInorder DAG is : \n\n");
dag(root);
getch();
}
btree *create(char exp[])
{
btree *temp;

int pos;
char ch;
void push(btree*);
btree *pop();
pos=0;
ch=exp[pos];
while(ch!='\0')
{
temp=((btree*)malloc(sizeof(btree)));
temp->left=temp->right=NULL;
temp->data=ch;
if(isalpha(ch))
push(temp);
else if(ch=='+' ||ch=='-' || ch=='*' || ch=='/')
{
temp->right=pop();
temp->left=pop();
push(temp);
}
else
printf("\n Invalid char Expression\n");
pos++;
ch=exp[pos];
}
temp=pop();
return(temp);
}
void push(btree *Node)
{
if(top+1 >=size)
printf("Error:Stack is full\n");
top++;
stack[top]=Node;
}
btree* pop()
{
btree *Node;
if(top==-1)
printf("\nerror: stack is empty..\n");
Node=stack[top];
top--;
return(Node);
}
void dag(btree *root)
{
btree *temp;
temp=root;

if(temp!=NULL)
{
dag(temp->left);
printf("%c",temp->data);
dag(temp->right);
}
}
