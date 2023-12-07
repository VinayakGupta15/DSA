#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int sumNodes(ListNode* head) {
    int sum = 0;
    while(head != NULL) {
        sum += head->val;
        head = head->next;
    }
    return sum;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    cout << "Sum of nodes in linked list: " << sumNodes(head) << endl;

    return 0;
}