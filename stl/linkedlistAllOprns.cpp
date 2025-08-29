#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// LinkedList class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at end
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted: " << value << endl;
    }

    // Update node at index
    void update(int index, int newValue) {
        Node* temp = head;
        int count = 0;
        while (temp != nullptr) {
            if (count == index) {
                cout << "Updated index " << index << " from " << temp->data << " to " << newValue << endl;
                temp->data = newValue;
                return;
            }
            temp = temp->next;
            count++;
        }
        cout << "Invalid index!" << endl;
    }

    // Delete node at index
    void deleteAt(int index) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (index == 0) {
            Node* toDelete = head;
            head = head->next;
            cout << "Deleted: " << toDelete->data << " at index 0" << endl;
            delete toDelete;
            return;
        }

        Node* temp = head;
        for (int i = 0; temp != nullptr && i < index - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid index!" << endl;
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        cout << "Deleted: " << toDelete->data << " at index " << index << endl;
        delete toDelete;
    }

    // Print all nodes
    void print() {
        Node* temp = head;
        cout << "Current List: ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Main function
int main() {
    LinkedList list;
    int choice, value, index;

    while (true) {
        cout << "\nMenu:\n1. Insert\n2. Update\n3. Delete\n4. Print\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insert(value);
                break;
            case 2:
                cout << "Enter index to update: ";
                cin >> index;
                cout << "Enter new value: ";
                cin >> value;
                list.update(index, value);
                break;
            case 3:
                cout << "Enter index to delete: ";
                cin >> index;
                list.deleteAt(index);
                break;
            case 4:
                list.print();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
