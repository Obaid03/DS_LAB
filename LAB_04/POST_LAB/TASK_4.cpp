/*Use Insertion Sort to sort an array of integers provided by the user. Then, implement the
Binary Search algorithm to find a target value within the newly sorted array. The program
should display the sorted array and the index of the found element or a message if it's not
present.*/

#include <iostream>
using namespace std;
int main(){
    int n,target;
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter element at index: "<<i+1<<endl;
        cin>>arr[i];
    }

    cout<<"Enter the element you want to search"<<endl;
    cin>>target;

    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 &&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

    cout<<"Sorted Array --> ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
    
    int left=0,right=n-1,index=-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==target){
            index=mid;
            break;
        }else if(arr[mid]<target){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }

    if(index==-1){
        cout<<"Element not Found"<<endl;} 
    else{
        cout<<"Element Found at index --> "<<index+1<<endl;
    }
    delete[] arr;
}