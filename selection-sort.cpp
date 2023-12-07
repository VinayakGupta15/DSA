#include<iostream>
using namespace std;
void swap (int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionsort(int arr[], int n){
    int i,j,minidx;
    for(i=0; i <n-1 ; i++){
        minidx = i;
        for( j = i+1 ; j < n ; j++)
        if(arr[j] < arr[minidx])
        minidx = j;
        swap(&arr[minidx], &arr[i]);
    }
}
void printarray(int arr[], int size){
    int i;
    for(i=0; i<size; i++)
    cout<<arr[i] <<" ";
    cout<<endl;
}
int main(){
    int arr[] = {64, 34, 25, 12, 22, 11,};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr, n);
    cout<<"Sorted array: \n";
    printarray(arr, n);
    return 0;
}