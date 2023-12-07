#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void print_list() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insert_middle(int position, int data) {
        if (head == nullptr || position <= 0) {
            cout << "List is empty or invalid position" << endl;
            return;
        }

        Node* new_node = new Node(data);
        Node* temp = head;
        int index = 1;

        while (temp != nullptr && index < position) {
            temp = temp->next;
            index++;
        }

        if (index == 1) {
            new_node->next = head;
            head = new_node;
        } else if (temp != nullptr) {
            new_node->next = temp;
            Node* prev = head;
            int prev_index = 1;

            while (prev != nullptr && prev_index < position - 1) {
                prev = prev->next;
                prev_index++;
            }

            prev->next = new_node;
        } else {
            cout << "Position is greater than the current length of the linked list" << endl;
        }
    }
};

int main() {
    LinkedList llist;
    llist.head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    llist.head->next = second;
    second->next = third;

    llist.print_list();

    llist.insert_middle(2, 25);

    llist.print_list();

    return 0;
}