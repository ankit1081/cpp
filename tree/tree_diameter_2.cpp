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

pair<int , int> diameterFast(node*root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second +1;

    pair<int,int> ans;
    ans.first= max(op1,max(op2,op3));
    ans.second = max(left.second , right.second)+1;

    return ans;

}
int diameter(node*root){
    return diameterFast(root).first;
}
int main(){
    //5 17 21 -1 -1 23 -1 -1 24 28 -1 -1 -1
    node*root=NULL;
    root= buildTree(root);
    cout<<"Diameter of tree is : "<<diameter(root);

    return 0;
}
