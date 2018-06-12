// C++ program to reverse a linked list in groups
// of given size
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

/* Reverses the linked list in groups of size k
and returns the pointer to the new head node. */
struct Node* Reverse(struct Node* head, int k)
{

    struct Node *prev,*curr,*nex,*first,*last;
    first=curr=head;
    prev=NULL;
    int j=0;
    while(j<k &&curr!=NULL)
    {
        nex=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nex;
        j++;
    }
    head=prev;
    last=curr;
    while(curr!=NULL)
    {
        int j=0;
        while(j<k &&curr!=NULL)
        {
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
            j++;
        }
        first->next=prev;
        first=last;
        last=curr;
    }
    first->next=NULL;
	return head;
}

/* UTILITY FUNCTIONS */
/* Function to push a node */
void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print linked list */
void printList(struct Node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}

/* Drier program to test above function*/
int main(void)
{
	/* Start with the empty list */
	struct Node* head = NULL;

	/* Created Linked list is 1->2->3->4->5->6->7->8->9 */
	push(&head, 9);
	//push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	printf("\nGiven linked list \n");
	printList(head);
	head = Reverse(head, 3);

	printf("\nReversed Linked list \n");
	printList(head);

	return 0;
}
