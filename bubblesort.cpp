#include<iostream>
using namespace std;
int main() {
    int temp;
    int arr[] = {1,5, 8, 3, 9, 6, 7, 2};
    int n = sizeof(arr)/ sizeof(arr[0]);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j]){
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }
    for (int i=0; i<n; i++){
        cout<<arr[i]<<"   ";
    }
return 0;    
    }