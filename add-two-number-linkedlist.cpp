#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
};
struct Node *newNode(int data)
{
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}
 struct Node* addTwoLists (struct Node* first, struct Node* second);
void push(struct Node** head_ref, int new_data)
{
    struct Node* new_Node = newNode(new_data);
    new_Node->next = (*head_ref);
    (*head_ref)    = new_Node;
}
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf(" ");
}
void freeList(struct Node *Node)
{
	struct Node* temp;
    while(Node != NULL)
    {
        temp=Node;
        Node = Node->next;
        free(temp);
    }
}
int main(void)
{
   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {
	   struct Node* res = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;
	    cin>>n;
	    for(i=0;i<n;i++)
	    {
			cin>>x;
			push(&first, x);
	    }
         cin>>m;
	    for(i=0;i<m;i++)
	    {
			cin>>x;
	    push(&second, x);
	    }
		 res = addTwoLists(first, second);
	    printList(res);
if(first)
freeList(first);
if(second)
freeList(second);
//if(res)
//freeList(res);
   }
   return 0;
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*struct Node
{
    int data;
   Node* next;
}; */
//write a function returns the resultant linked list
Node* sum(Node *f,Node* s)
{
    int r=0;
    Node *temp,*head;
    temp=head=NULL;
    int p=0;
    while(f&&s)
    {
        r+=f->data+s->data;
        Node *t1=new Node();
        t1->data=r%10;
        t1->next=NULL;
        r=r/10;
        if(p==0)
        {
            p=1;
            temp=head=t1;
        }
        else
        {
            temp->next=t1;
            temp=t1;
        }
        f=f->next;
        s=s->next;
    }
    while(f)
    {
        r+=f->data;
        Node *t1=new Node();
        t1->data=r%10;
        t1->next=NULL;
        r=r/10;
        if(p==0)
        {
            p=1;
            temp=head=t1;
        }
        else
        {
            temp->next=t1;
            temp=t1;
        }
        f=f->next;
    }
    while(s)
    {
        r+=s->data;
        Node *t1=new Node();
        t1->data=r%10;
        t1->next=NULL;
        r=r/10;
        if(p==0)
        {
            p=1;
            temp=head=t1;
        }
        else
        {
            temp->next=t1;
            temp=t1;
        }
        s=s->next;
    }
    while(r)
    {
        Node *t1=new Node();
        t1->data=r%10;
        t1->next=NULL;
        r=r/10;
        if(p==0)
        {
            p=1;
            temp=head=t1;
        }
        else
        {
            temp->next=t1;
            temp=t1;
        }
    }
    return head;
}
Node*  addTwoLists(Node* first, Node* second){
  // Code here
  int sum1=0;
  Node *head=sum(first,second);
  return head;
}
