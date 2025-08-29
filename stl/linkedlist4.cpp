/*
Program No - 62
Topic      - Linked List
Program    - Insertion at Start
Date       - 07.04.2025
Branch     - CSE (338)
Session No.- 12
Author     - Vivek Agrawal
*/

#include<iostream>
using namespace std;

/** Node class for singly linked list */
class node {
public:
    int data;       // Stores the data value
    node *next;     // Pointer to the next node

    //node(int data = -1) : data(data), next(nullptr) {}  // Constructor with default values
    node(int input = -1)  //constructor
    {
    	data=input;
    	next=nullptr; //NULL
    }
};

/** Global pointers and length for singly linked list */
node *first = nullptr;  // Head of the list ~ Engine
node *last = nullptr;   // Tail of the list ~ Guard
int length = 0;         // Number of nodes in the list ~ kitne dibbe hai?

//--------------------------------------------------------------------------------------
// Purpose: Inserts a new node at the start of the singly linked list
/*
Pseudocode:
1. Create a new node with the given data.
2. If list is empty:
   a. Set first and last to new_node.
3. Else:
   a. Set new_node's next to first.
   b. Set first to new_node.
4. Increment length.
*/
void insert_at_start(int data) {
    node* new_node = new node(data);  // Create a new node with data
    if (first == nullptr && last==nullptr)
    {           // Check if list is empty
        first = new_node;             // Set first to new node
        last = new_node;              // Set last to new node
        cout << "FIRST NODE CREATED with Data " << data << endl;
    } else {
        new_node->next = first;       // Link new node to current first
        first = new_node;             // Update first to new node
        cout << "NODE INSERTED AT START with Data " << data << endl;
    }
    length++;                         // Increase list length
}

int main()
{
	int data;
	cout<<"ENter Data";
	cin>>data;
	insert_at_start(data);

	insert_at_start(data);
}
