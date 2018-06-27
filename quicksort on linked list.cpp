// C++ program for Quick Sort on Singly Linled List
#include <iostream>
#include <cstdio>
using namespace std;

/* a node of the singly linked list */
struct Node
{
    int data;
    struct Node *next;
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new Node;

    /* put in the data  */
    new_node->data  = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* A utility function to print linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d  ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Returns the last node of the list
struct Node *getTail(struct Node *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

// Partitions the list taking the last element as the pivot
struct Node *partition(struct Node *head, struct Node *end)
{
    struct Node *pivot = end;
    struct Node *prev = head, *cur = head;

    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot)
    {
        if (cur->data <= pivot->data) // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change tail
            int temp=prev->data;
            prev->data=cur->data;
            cur->data=temp;
            prev=prev->next;
        }
        cur=cur->next;
    }
    int temp=prev->data;
    prev->data=cur->data;
    cur->data=temp;
    return prev;
}


//here the sorting happens exclusive of the end node
void quickSortRecur(struct Node *head, struct Node *end)
{
    if (head==NULL ||  head->next==end || head==end)
        return;
    struct Node *pivot = partition(head, end);
    struct Node* temp=head;
    while(temp!=pivot && temp->next!=pivot)
    {
        temp=temp->next;
    }
    quickSortRecur(head,temp);
    if(pivot!=end)
    quickSortRecur(pivot->next,end);
}
struct Node* quickSort(struct Node *headRef)
{
    struct Node* t=getTail(headRef);
    quickSortRecur(headRef,t);
    return headRef;
}

// Driver program to test above functions
int main()
{
    struct Node *a = NULL;
    push(&a, 1);
    push(&a, 4);
    push(&a, 3);
    push(&a, 4);
    push(&a, 1);

    cout << "Linked List before sorting \n";
    printList(a);
    a=quickSort(a);
    cout << "Linked List after sorting \n";
    printList(a);

    return 0;
}
