#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// function to create a new node in heap
Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// function to insert a new node at the end of the linked list
void insertNode(Node** head, int data) {
    Node* new_node = newNode(data);
    if(*head == NULL) {
        *head = new_node;
        return;
    }
    Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// function to perform linear search on the linked list
bool linearSearch(Node* head, int key) {
    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    Node* head = NULL;
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);

    int key = 30;
    if(linearSearch(head, key)) {
        cout << "Element " << key << " is present in the linked list" << endl;
    } else {
        cout << "Element " << key << " is not present in the linked list" << endl;
    }

    return 0;
}