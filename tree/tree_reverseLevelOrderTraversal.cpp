#include<iostream>
#include<queue>
#include<stack>
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
void reverseLevelOrderTraversal(node*root){
    if(root == NULL){
        return;
    }
    queue<node*>q;
    stack<node*>s;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*temp = q.front();
        q.pop();

        s.push(temp);


        if(temp == NULL){
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            if(temp->right){
                q.push(temp->right);
            }
            if(temp->left){
                q.push(temp->left);
            }

        }
    }
    cout<<"Reverse order Traversal :";
    while (!s.empty()){
        node*temp = s.top();
        s.pop();
        if (temp == NULL){
            cout<<endl;
        }
        else{
            cout <<temp->data<<" ";
        }

    }
}
int main(){
    // 5 17 21 -1 -1 23 -1 -1 24 28 -1 -1 -1
    node*root=NULL;
    root= buildTree(root);
    reverseLevelOrderTraversal(root);
    return 0;
}
