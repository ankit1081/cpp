#include<iostream>
using namespace std;
class node{
public:
    int data;
    node*left;
    node*right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node*buildTree(node*root){
    int data;

    cin>>data;
    root= new node(data);


    if(data == -1){
        return NULL;
    }
    cout<<"Enter data for left of :" <<data<<endl;
    root ->left = buildTree(root->left);
    cout<<"Enter data for right of "<<data <<endl;
    root->right = buildTree(root->right);
    return root;
}
void inOrderTraversal(node*root){
    if(root== NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
int main(){
    // 5 17 21 -1 -1 23 -1 -1 24 28 -1 -1 -1
    //10 20 -1 40 -1 -1 30 -1 50 60 -1 -1 -1
    node*root=NULL;
    root= buildTree(root);
    cout<<"Inorder Traversal of tree is : ";
    inOrderTraversal(root);
    return 0;
}
