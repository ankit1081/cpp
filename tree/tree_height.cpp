#include<iostream>
using namespace std;
class node{
public:
    int data;
    node*left;
    node*right;

    node(int d){
        this ->data= d;
        this ->left= NULL;
        this ->right= NULL;
    }
};
node*buildTree(node*root){
    int data;
    cin>>data;
    root= new node(data);

    if(data == -1){
        return NULL;
    }
    cout<<"Enter data for left of "<< data <<endl;
    root ->left = buildTree(root->left);
    cout<<"Enter data for right of "<<data <<endl;
    root->right = buildTree(root->right);
    return root;
}
int height(node*root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right = height(root->right);
    int ans = max(left,right)+1;
    return ans;
}
int main(){
    //5 17 21 -1 -1 23 -1 -1 24 28 -1 -1 -1
    node*root=NULL;
    root= buildTree(root);
    cout<<"Height of tree is : "<<height(root);
    return 0;
}
