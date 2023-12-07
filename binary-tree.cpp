#include <stdlib.h>
#include <iostream>
using namespace std;
struct bintreenode{
 int data;
 bintreenode *left;
 bintreenode *right;
};
class list{
 bintreenode *root;
 public:
 list(){
    root=NULL;
 }
 int isempty(){
    return(root==NULL);
 }
 void insert(int item);
 void displaybintree();
 void printbintree(bintreenode*);
};
void list::insert(int item){
 bintreenode * newbintreenode = new bintreenode;
 bintreenode * parent;
 newbintreenode->data=item;
 newbintreenode->left=NULL;
 newbintreenode->right=NULL;
 if (isempty()){
    root=newbintreenode;
    }else {
      bintreenode *ptr;
      ptr = root;
      while ((ptr != NULL)){
        parent = ptr;
        if (item<ptr->data)
        ptr = ptr->left;
        else
       ptr = ptr->right;
}
if (item<parent->data)
parent->left = newbintreenode;
else
parent->right = newbintreenode;
}}
void list::displaybintree(){
 printbintree(root);
}
void list::printbintree(bintreenode *node){
 if (node == NULL){
    return;
 }
 printbintree(node->left);
 cout<<" "<<node->data<<endl;
 printbintree(node->right);
}
int main(){
 list b;
 b.insert(10);
 b.insert(5);
 b.insert(20);
 b.insert(3);
 b.insert(4);
 b.insert(7);
 b.insert(6);
 cout<<"Binary tree created: "<<endl;
 b.displaybintree();
 return 0;
}