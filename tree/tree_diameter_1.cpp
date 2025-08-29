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
int diameter(node*root){
    if (root ==NULL){
        return 0;
    }
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left)+1+height(root->right);
    int ans = max(op1,max(op2,op3));
    return ans;

}
int main(){
    //5 17 21 -1 -1 23 -1 -1 24 28 -1 -1 -1
    node*root=NULL;
    root= buildTree(root);
    cout<<"Diameter of tree is : "<<diameter(root);
    return 0;
}
