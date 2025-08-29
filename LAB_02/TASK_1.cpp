/*Task #1:
Implement a program that dynamically allocates a 1D array of integers.
=> The size should be given by the user.
=> Initialize all elements with zero.
=> Then, let the user update values at different positions.
=> Finally, print the array and deallocate memory properly.*/

#include <iostream>
using namespace std;
int main(){
    int *arr,size=0,i;
    cout<<"Enter Size of Array"<<endl;
    cin>>size;
    arr=new int[size];
    arr[0]=0;
    for(i=0;i<size;i++){
        cout<<"Enter Element "<<i+1<<endl;
        cin>>arr[i];
    }
    for(i=0;i<size;i++){
        cout<<"Element -->  "<<i<<endl;
    }
    delete [] arr;
}
