
/*
Program No - 61
Topic      - Linked List
Program    - Node & pointers
Date       - 07.04.2025
Branch     - CSE 338
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

int main()
{

}
