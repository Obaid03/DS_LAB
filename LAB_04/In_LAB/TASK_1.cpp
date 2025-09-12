/*
Implement a linear search algorithm to find a specific integer in an array. The program
should take an array of integers and a target value as input from the user. Print the index of
the target value if it's found or a message indicating that the element is not in the array.
*/
#include <iostream>
using namespace std;
int main(){
    int *array,n,target,index=-1;
    cout<<"Enter Number Of Element In the Array"<<endl;
    cin>>n;
    array=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter Element at index "<<i+1<<"\t";
        cin>>array[i];
    }
    cout<<"Enter Element You want to Search"<<endl;
    cin>>target;
    for(int i=0;i<n;i++){
        if(target==array[i]){
            index=i+1;
            break;
        } 
    }
    if(index==-1){
        cout<<"Element Not Found"<<endl;
    }
    else{
        cout<<"Element Found at Index  "<<index<<endl;
    }
    delete []array;

}
