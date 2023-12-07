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

void insertmiddle(node *&head, int position, int data)
{
    if (head == 0 || position <= 0)
    {
        cout << "List is empty or invalid position" << endl;
        return;
    }

    node *temp = head;
    int index = 1;

    while (temp != 0 && index < position)
    {
        temp = temp->ptr;
        index++;
    }

    node *newNode = new node(data);
    newNode->ptr = temp;

    if (index == 1)
    {
        head = newNode;
    }
    else
    {
        node *prev = head;
        int prevIndex = 1;

        while (prev != 0 && prevIndex < position - 1)
        {
            prev = prev->ptr;
            prevIndex++;
        }

        prev->ptr = newNode;
    }
}

int main()
{
    node *head = new node(10);
    head->ptr = new node(20);
    head->ptr->ptr = new node(30);

    print(head);

    insertmiddle(head, 2, 25);

    print(head);

    return 0;
}