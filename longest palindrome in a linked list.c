// C++ program to find longest palindrome
// sublist in a list in O(1) time.
#include<bits/stdc++.h>
using namespace std;

//structure of the linked list
struct Node
{
	int data;
	struct Node* next;
};

// function for counting the common elements
int countCommon(Node *a, Node *b)
{
	int count=0;
	while(a&&b&&a->data==b->data)
	{
	    count++;
	    a=a->next;
	    b=b->next;
	}
	return count;
}

// Returns length of the longest palindrome
// sublist in given list
int maxPalindrome(Node *head)
{
	int result=0;
	Node *curr,*nex,*prev;
	prev=NULL;
	curr=head;
	while(curr)
	{
	    nex=curr->next;
	    curr->next=prev;
	    result=max(result,2*countCommon(prev,nex)+1);
	    result=max(result,2*countCommon(curr,nex));
	    prev=curr;
	    curr=nex;
	}
	return result;
}

// Utility function to create a new list node
Node *newNode(int key)
{
	Node *temp = new Node;
	temp->data = key;
	temp->next = NULL;
	return temp;
}

/* Drier program to test above functions*/
int main()
{
	/* Let us create a linked lists to test
	the functions
	Created list is a: 2->4->3->4->2->15 */
	Node *head = newNode(2);
	head->next = newNode(2);
	head->next->next = newNode(2);
	head->next->next->next = newNode(6);
	head->next->next->next->next = newNode(3);
	head->next->next->next->next->next = newNode(2);

	cout << maxPalindrome(head) << endl;
	return 0;
}
