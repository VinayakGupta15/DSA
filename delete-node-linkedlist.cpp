#include<iostream>
using namespace std;
struct node {
    int data; 
    node *next;
    node(int x) { 
        data = x;
        next = NULL;
    }
};
void deleteNode(node *&head, int val) {
    if (head == NULL) {
        cout << "Element is not present in list" << endl;
        return;
    }
    if (head->data == val) {
        node *temp = head;
        head = head->next; 
        delete temp; 
        return;
    }
    node *curr = head; 
    while (curr->next != NULL && curr->next->data != val) {
        curr = curr->next; 
    }
    if (curr->next != NULL) {
        node *temp = curr->next; 
        curr->next = temp->next; 
        delete temp; 
    }
    else {
        cout << "Element is not present in list" << endl;
    }
}
void push(node *&head, int data) {
    node *newnode = new node(data); 
    newnode->next = head; 
    head = newnode;
}
void print(node *head) {
    if (head == NULL) {
        cout << endl;
        return;
    }
    cout << head->data << " ";
    print(head->next);
}
int main() {
    node *head = NULL;
    push(head, 10);
    push(head, 20);
    push(head, 30);
    push(head, 40);
    push(head, 50);
    cout << "Linked List before deletion: " << endl;
    print(head);
    deleteNode(head, 20);
    deleteNode(head, 50);
    cout << "Linked List after deletion: " << endl;
    print(head);
    return 0;
}
