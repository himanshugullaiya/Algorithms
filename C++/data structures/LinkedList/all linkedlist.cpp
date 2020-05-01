#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next;
};

// **** ENTERING ELEMENT *** ///

void push(Node** head_ref, int new_data) //add node in front
{
	Node* new_node = new Node(); //create new node
	new_node->data = new_data; //change data of new node to the given in function
	new_node->next = *head_ref; // new node & head both are now pointing to where head was pointing to earlier
	*head_ref = new_node; // now head is pointing to the new node
}

void insertafter(Node* prev_node, int new_data) //add node after some node
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

void append(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node -> data = new_data;
	new_node -> next = NULL;
	
	
	if (*head_ref == NULL)
		{
			*head_ref = new_node;
			return;
		}
	
	Node *pointer;
	pointer = *head_ref;

	while(pointer->next != NULL)
		pointer = pointer->next;
	
	pointer->next = new_node;
	return;
}


void printlist(Node *pointer)
{
	while(pointer != NULL)
		{
			cout<<" "<<pointer->data;
			pointer = pointer->next;
		}
}

// *** ENTERING AN ELEMENT ********//

// https://www.geeksforgeeks.org/reverse-a-linked-list/ animation
void reverse(Node** head)
{
	Node* prev = NULL;
	Node* nxt = NULL;
	Node* curr = *head;
	
		while(curr != NULL)
		{	
			nxt = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nxt;
		}
		
		*head = prev;

}

int main()
{
	Node *head = NULL;	
	for(int i = 1; i <= 5; i++)
		append(&head, i);
	
//	insertafter(head->next, 8);
	printlist(head);
	
	cout<<endl;
	
	reverse(&head);
	printlist(head);
	
	
	
	
}



