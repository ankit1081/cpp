
/*
Program No - 65
Topic      - Linked List
Program    - Display
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

//--------------------------------------------------------------------------------------
// Purpose: Inserts a new node at the end of the singly linked list
/*
Pseudocode:
1. Create a new node with the given data.
2. If list is empty:
   a. Set first and last to new_node.
3. Else:
   a. Set last's next to new_node.
   b. Set last to new_node.
4. Increment length.
*/
void insert_at_end(int data) {
    node *new_node = new node(data);  // Create a new node with data
    if (first == nullptr && last==nullptr)
     {           // Check if list is empty
        first = new_node;             // Set first to new node
        last = new_node;              // Set last to new node
        cout << "FIRST NODE CREATED with Data " << data << endl;
    } else {
        last->next = new_node;        // Link current last to new node
        last = new_node;              // Update last to new node
        cout << "NODE INSERTED AT END with Data " << data << endl;
    }
    length++;                         // Increase list length
}

//--------------------------------------------------------------------------------------
// Purpose: Inserts a node at a specific position (0-based index)
/*
Pseudocode:
1. If position < 0, print error and return.
2. If position == 0, call insert_at_start.
3. If position >= length, call insert_at_end.
4. Else:
   a. Create a new node with data.
   b. Traverse to node before position.
   c. Link new_node to temp's next.
   d. Set temp's next to new_node.
5. Increment length.
*/
void insert_at_position(int data, int position) {
    if (position < 0) {               // Validate position
        cout << "Invalid position" << endl;
        return;
    }
    if (position == 0) {              // If inserting at start
        insert_at_start(data);        // Reuse insert_at_start function
        return;
    }
    if (position >= length) {         // If inserting at or beyond end
        insert_at_end(data);          // Reuse insert_at_end function
        return;
    }
    node* new_node = new node(data);  // Create a new node with data
    node* temp = first;               // Start traversal from first
    for (int i = 0; i < position - 1; i++) {  // Move to node before position
        temp = temp->next;
    }
    new_node->next = temp->next;      // Link new node to next node
    temp->next = new_node;            // Link previous node to new node
    cout << "NODE INSERTED AT POSITION " << position << " with Data " << data << endl;
    length++;                         // Increase list length
}

//--------------------------------------------------------------------------------------
// Purpose: Displays all nodes in the singly linked list
/*
Pseudocode:
1. If list is empty, print "LL Empty".
2. Else:
   a. Start temp at first.
   b. While temp exists:
      i. Print temp's data.
      ii. Move temp to next.
   c. Print "NULL".
*/
void display() {
    if (first == nullptr || last==nullptr)
     {           // Check if list is empty
        cout << "LL Empty" << endl;
        return;
    }
    cout << "Data in LL: ";
    node* temp = first;               // Start traversal from first
    while (temp != nullptr) {         // Continue until end of list
        cout << temp->data << "----->";  // Print current node's data
        temp = temp->next;            // Move to next node
    }
    cout << "NULL" << endl;           // Indicate end of list
}


int main()
{
	int data;
	cout<<"ENter Data";
	cin>>data;
	insert_at_start(data+1);
    display();
	insert_at_start(data+2);
    display();
    insert_at_end(data+3);
    display();
    insert_at_end(data+4);
    display();
    int pos=3;
    insert_at_position(data+5, pos);
    display();

}
