#include <iostream>
using namespace std;
class stack
{
public:
    int arr[5];
    int top = -1; // top of the stack
    void push(int x)
    { // function to insert element in stack
        if (top >= 4)
        {
            cout << "Stack is full";
        }
        else
        {
            top++;
            arr[top] = x;
        }
    }
    void pop()
    {
        if (top < 0)
        {
            cout << "stack is empty";
        }
        else
        {
            cout << arr[top--];
        }
    }
    void print(){
        for (int i = top; i >= 0; i--){
            cout<<arr[i]<<endl;
        }
    }
};
int main(){
    stack s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.print();
    s.pop();
}