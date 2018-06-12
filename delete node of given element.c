// A C++ program to demonstrate deletion of last
// Node in singly linked list
#include <bits/stdc++.h>

// A linked list Node
struct Node {
	int key;
	struct Node* next;
};

Node* deleteLast(Node* head, int key)
{
	struct Node *t1,*t2,*prev,*curr;
	prev=t1=NULL;
	curr=head;
	while(curr!=NULL)
	{
	    if(curr->key==key)
	        t1=prev;
	   prev=curr;
	   curr=curr->next;
	}
	if(t1==NULL && head->key==key)
	head=head->next;
	else
	{
	   // printf("%d\n",t1->key);
	    t1->next=t1->next->next;
	}
	return head;
}

/* Utility function to create a new node with
given key */
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->next = NULL;
	return temp;
}

// This function prints contents of linked list
// starting from the given Node
void printList(struct Node* node)
{
	while (node != NULL) {
		printf(" %d ", node->key);
		node = node->next;
	}
}

/* Drier program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(5);
	head->next->next->next->next = newNode(10);
	//head->next->next->next->next->next = newNode(10);

	puts("Created Linked List: ");
	printList(head);
	head=deleteLast(head, 10);
	puts("\nLinked List after Deletion of 1: ");
	printList(head);
	return 0;
}
