#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

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


    void findMax() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        int maxVal = head->data;
        Node* temp = head->next;

        while (temp != nullptr) {
            if (temp->data > maxVal) {
                maxVal = temp->data;
            }
            temp = temp->next;
        }

        cout << "Largest value in the list: " << maxVal << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n2. Find Max\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insert(value);
                break;
            case 2:
                list.findMax();
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
