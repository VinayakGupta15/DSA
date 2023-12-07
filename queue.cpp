#include <iostream>
using namespace std;

class queue
{
public:
    int arr[5];
    int front = -1;
    int rare = -1;

    void nqueue(int x)
    {
        if (front == 4)
        {
            cout << "over flow";
        }
        else
        {
            if (front == -1)
            {
                front++;
            }
            arr[++front] = x;
        }
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "under flow";
        }
        else
        {
            cout << "Removed element: " << arr[rare++] << endl;
            if (rare > front)
            {
                rare = front = -1;
            }
        }
    }

    void display()
    {
        for (int i = rare; i <= front; i++)
        {
            cout << arr[i] << endl;
        }
    }

    bool isEmpty()
    {
        return front == -1;
    }
};

int main()
{
    queue q;
    q.nqueue(2);
    q.nqueue(3);
    q.nqueue(4);

    if (!q.isEmpty())
    {
        q.display();
        q.dequeue();
    }
    else
    {
        cout << "Queue is empty" << endl;
    }

    return 0;
}