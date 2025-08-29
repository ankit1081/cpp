#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val = 0): data(val), left(nullptr), right(nullptr){}
};

Node* create_tree()
{
    int val;
    cout<<"Enter value:";
    cin>>val;
    if(val==-1){
        return nullptr;
    }

    Node *root = new Node(val);

    cout<<"Enter the left child of "<<val<<endl;
    root->left = create_tree();
    cout<<"Enter the right child of "<<val<<endl;
    root->right = create_tree();

    return root;
}
int main(){
    Node*root = create_tree();
}
