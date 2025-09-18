/*Implement the Selection Sort algorithm. The program should take an array of integers from
the user, find the smallest element, and exchange it with the element at the first position.
This process should continue until the array is completely sorted. Display the sorted array
to the user.*/

#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element at index: "<<i+1<<endl;
        cin>>arr[i];
    }

    cout<<"Actual Array --> ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;

    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
            }
        }
            int temp=arr[i];
            arr[i]=arr[min_index];
            arr[min_index]=temp;
    }
    cout<<"Sorted Array --> ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;

    delete[] arr;
}