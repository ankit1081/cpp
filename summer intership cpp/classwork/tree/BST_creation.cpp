#include<iostream>
using namespace std;
class node{
public:
    int data;
    node*left;
    node*right;

    node(int d=0): data(d), left(NULL),right(NULL)
    {
        cout<<"New node created with data : "<< data<<endl;}

};
node*insertBST(node*root,int val){
    if(root== NULL){
        cout<<"\nNew node created with value : "<<val;
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
int main(){
    node*root = NULL;
    int elements[]={50,30,70,20,40,60,80};
    for (int val:elements){
        root= insertBST(root,val);
    }
}
