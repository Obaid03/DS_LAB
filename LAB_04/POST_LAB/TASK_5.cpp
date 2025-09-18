/*Implement the Interpolation Search algorithm. 
The program should take a sorted array with uniformly distributed values 
and a target value from the user. 
The algorithm should estimate the position of the target and check if the estimated position 
holds the correct value. 
If the element is found, print its index; otherwise, indicate that it's not present.*/

#include <iostream>
using namespace std;

int interpolationSearch(int arr[],int n,int target){
    int low=0,high=n-1;
    while(low<=high && target>=arr[low] && target<=arr[high]){
        if(low==high){
            if(arr[low]==target) return low;
            return -1; 
        }
        int pos=low+ ((target-arr[low])* (high-low)) / (arr[high]-arr[low]);

        if(arr[pos]==target)   return pos;
        else if(arr[pos]<target)  low=pos+1;
        else high=pos-1;
    }
    return -1;
}
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

    int index=interpolationSearch(arr,n,target);
    if(index==-1){
        cout<<"Element not Found"<<endl;
    }else{
        cout<<"Element Found at index --> "<<index+1<<endl;
    }
    delete[] arr;
}