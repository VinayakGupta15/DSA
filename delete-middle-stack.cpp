#include<iostream>
#include<stack>
using namespace std;

void deleteMidElement(stack<int> &s) {
    if (s.empty()) {
        cout << "Stack is empty." << endl;
        return;
    }

    stack<int> tempStack;
    int midIndex = s.size() / 2;
    int currentIndex = 0;

    while (!s.empty()) {
        if (currentIndex == midIndex) {
            // If it is the middle element, remove it.
            s.pop();
        } else {
            // Move the elements to a temporary stack.
            tempStack.push(s.top());
        }
        s.pop();
        currentIndex++;
    }

    // Move the elements back to the original stack.
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    deleteMidElement(s);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}                                              