#include<iostream>
using namespace std;
class node{
public:
    int data;
    node*left;
    node*right;

    node(int d=0): data(d), left(NULL),right(NULL){cout<<"New node created with data : "<< data<<endl;}

};
void create_tree(){
    node *root = new node(10);
    node *one = new node(15);
    node *two = new node(20);

    root->left = one;
    root ->right = two;

    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;


}
void test(){
    int data;
    cout<<"Enter root data : ";
    cin>>data;
    if(data == -1){
        cout<<"\n_________Returned__________\n";
        return;
    }
    cout<<"\nnew node create and linked\n";
    test();
}
node*new_node(){
    int data;

    cin>>data;
    if (data == -1 ){
        return NULL;
    }
    node*root = new node();
    cout<<"\nNew node created with data" << root-> data<<endl;
    cout<<"Enter left :";
    root->left= new_node();
    cout<<"Enter right :";
    root->right = new_node();

    return root;
}
void create_tree_2(){
    node *root= new_node();
    root->left= new_node();
    root->right = new_node();

    cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;

}
int main(){
    //5 17 21 -1 -1 23 -1 -1 24 28 -1 -1 -1
    //10 20 -1 40 -1 -1 30 -1 50 60 -1 -1 -1
    create_tree();
    test();
    create_tree_2();
}
