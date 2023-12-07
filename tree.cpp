#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node (int data){
        this->data = data;
        left=right=NULL;
    }
};
void inorderTraversal(Node* node){
    if(node==NULL) 
    return ;

    inorderTraversal(node->left);
    cout<<node->data<<" ";
    inorderTraversal(node->right);
}
int main(){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    cout << "Inorder traversal of binary tree is \n";
    inorderTraversal(root);
    return 0;
}