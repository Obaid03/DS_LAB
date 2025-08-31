/*
Task #4:
Create a dynamic program that manages monthly expenses for a family.
=> Use a 1D dynamic array to store expenses for n months.
=> Add a feature to resize the array if the user wants to track more months later.
=> Compute and display the total and average expenses.
*/
#include <iostream>
using namespace std;
void update(double *&array,int &size,double &Total){
    int a;
    cout<<"Enter Number of months you want to add\t";
        cin>>a;
        if(a>0){
            double *newarr =new double[size+a];
            for(int i=0;i<size;i++){
                newarr[i]=array[i];
            }
            for(int i=size;i<size+a;i++){
                cout<<"Enter Your expense for Month "<<i+1<<"\t";
                cin>>newarr[i];
                Total+=newarr[i];
            }
            size+=a;
            delete [] array;
            array=newarr;
        }
        else{
            return;
        }
            
        

}
int main(){
    double *array,Total=0.0,Avg;
    int n,flag;
    cout<<"Enter Number Of months\t";
    cin>> n;
    array=new double[n];
    for(int i=0;i<n;i++){
        cout<<"Enter Your expense for Month "<<i+1<<"\t";
        cin>>array[i];
        Total+=array[i];
    }
    cout<<"\nEnter 1 if you want to add month\nEnter 0 if u dont want to add month"<<endl;
    cin>>flag;
    if(flag==1){
        update(array,n,Total);
    }
    else{
        cout<<"No months Added"<<endl;
    }
    Avg=Total/n;
    cout<<"Total Expense -->    "<<Total<<endl;
    cout<<"Average Expense -->      "<<Avg<<endl;
    delete [] array;
}