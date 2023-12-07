#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *ptr;
    node(int d)
    {
        this->data = d;
        this->ptr = 0;
    }

    node(node *&head)
    {
        int newdata;
        node *temp = new node(newdata);
        temp->ptr = head;
        head = temp;
    }
};
void print(node *&head)
{
    if (head == 0)
    {
        cout << "List is empty" << endl;
        return;
    }

    node *temp = head;
    while (temp != 0)
    {
        cout << temp->data << "       ";
        temp = temp->ptr;
    }
    cout << endl;
};
void insertattail(node *&tail)
{
    int newdata;
    node *temp = new node(newdata);
    tail->ptr = temp;
    tail = temp;
}
int main()
{
    node *n = new node(10);
    cout << n->data << endl;
    node *head = n;
    node *tail = n;

    head = new node(8);
    head->ptr = n;

    head = new node(4);
    head->ptr = tail;

    print(head);

    head = new node(600);
    head->ptr = tail;

    print(head);

    head = new node(300);
    head->ptr = tail;

    print(head);

    tail = new node(65);
    print(tail);
    return 0;
}