/*Write a program to implement the Bubble Sort algorithm. 
  The program should take an array of integers as input from the user,
  sort the array using bubble sort, and then display both the unsorted 
  and sorted arrays.*/

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
      int temp;
      for(int i = 0;i<n;i++){
          for(int j=0;j<n-1;j++){
              if(arr[j]>arr[j+1]){
                  temp=arr[j];
                  arr[j]=arr[j+1];
                  arr[j+1]=temp;
              }}}
  
      cout<<"Sorted Array --> ";
      for(int i=0;i<n;i++){
          cout<<arr[i]<<",";
      }
      cout<<endl;

      delete[] arr;
  }
  