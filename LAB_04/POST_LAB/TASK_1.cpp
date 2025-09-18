/*Implement a linear search algorithm to find a specific integer in an array. The program
should take an array of integers and a target value as input from the user. Print the index of
the target value if it's found or a message indicating that the element is not in the array.*/

#include <iostream>
using namespace std;
int main(){
    int n,target;
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>n;
    int *arr=new int[n];

    for(int i=0;i<n;i++){
        cout<<"Enter Elemet at index: "<<i+1<<endl;
        cin>>arr[i];
    }
    cout<<"Enter Element You want to Search"<<endl;
    cin>>target;
    int index = -1;
    for(int i=0;i<n;i++){
        if(arr[i] == target){
            index = i;
            break;
        }}
    if(index==-1){
        cout<<"Element not Found"<<endl;
    } else {
        cout<<"Element Found at index --> " <<index+1<<endl;
    }
    delete [] arr;
}