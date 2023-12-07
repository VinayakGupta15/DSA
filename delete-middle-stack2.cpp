#include<bits/stdc++.h>
using namespace std;
//Recursive function to remove middle item of the stack
void solve(stack<int>&s,int &count,int size){
    if(count==size){
        s.pop();
        return;
    }
    //top function is used to return the element at top of stack
    int x=s.top(); //stores top element of the stack
    s.pop();
    count=count+1;
    solve(s,count,size);
    s.push(x);
    return;
}
int main()
{
    stack<int>s;
    //code to insert element in stack
    for(int i=1;i<=6;i++){
        s.push(i);
    }
    int count=0;
    
    //function call
    solve(s,count,s.size()/2);
    //code to display elements of the stack
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}