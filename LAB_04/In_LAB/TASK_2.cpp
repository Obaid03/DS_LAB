#include<iostream>
using namespace std;
int key=93;
void NewArray(int *&array,int size,int &position){
    int *newarray=new int [size+1];
    int index=0;
    for(int i=0;i<size+1;i++){
        if(i==position){
            newarray[i]=key;
        }
        else{
            newarray[i]=array[index];
            index++;
        }
        array=newarray;
        size++;
    }


}
int main(){
     int *array,n,index=-1,mid,position,found;
    cout<<"Enter Number Of Employees"<<endl;
    cin>>n;
    array=new int[n];
    for(int i=0;i<n;i++){
        cout<<"Enter ID Of Employee "<<i+1<<"\t";
        cin>>array[i];
    }
    cout<<"Searching"<<endl;
    int right=n-1;
    int left=0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (array[mid] == key) {
            cout<<"Id found at index "<<mid+1<<endl;
            found=1;
            break;
        }
        else if (array[mid] < key) {
            left = mid + 1;
        }
        else {
        right = mid - 1;
        }
    }
    if(!found){
        right=position;
        NewArray(array,n,position);
    }
    cout<<"Printing Array"<<endl;
        for(int i=0;i<n;i++){
            cout<<"ID of Employee "<<i+1<<" is "<<array[i]<<endl;
        }
        delete [] array;
    

}
