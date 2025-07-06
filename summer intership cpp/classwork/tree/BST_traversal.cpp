#include<iostream>
using namespace std;
class node{
public:
    int data;
    node*left;
    node*right;

    node(int d=0): data(d), left(NULL),right(NULL)
    {

    }
};
node*insertBST(node*root,int val){
    if(root== NULL){
        cout<<"\nNew node created with value : "<<val<<endl;
        return new node(val);
    }
    else if(val<root->data){
        root->left = insertBST(root->left,val);
    }
    else if (val>root->data){
        root->right = insertBST(root->right,val);
    }
    else{
        cout<<"Duplicate value";
    }
    return root;
}
void preOrderTraversal(node*root){
    if(root== NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);

    preOrderTraversal(root->right);
}
void inOrderTraversal(node*root){
    if(root== NULL){
        return;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}
void postOrderTraversal(node*root){
    if(root== NULL){
        return;
    }
    postOrderTraversal(root->left);

    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}
int main(){
    node*root = NULL;
    int elements[]={50,30,70,20,40,60,80};
    for (int val:elements){
        root= insertBST(root,val);
    }
    cout<<"\nPre order travesal :";
    preOrderTraversal(root);
    cout<<"\nIn order travesal :";
    inOrderTraversal(root);
    cout<<"\nPost order travesal :";
    postOrderTraversal(root);
}
