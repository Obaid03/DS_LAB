/*Task #2:
Write a program that uses a dynamic 2D array to represent a seating chart in a classroom.
=> Rows represent benches, columns represent seats on each bench.
=> Initialize the array with 0 (empty).
=> Let the user fill seats (1 for occupied).
=> Print the final seating chart in matrix form*/
#include<iostream>
using namespace std;
int main(){
    int **chart,row,column,i,input;
    cout<<"Enter Row Size"<<endl;
    cin>>row;
    cout<<"Enter Column Size"<<endl;
    cin>>column;
    chart=new int*[row];
    for(i=0;i<column;i++){
        chart[i]=new int[column];
    }
    chart[0][0]=0;
    cout<<"Enter '0' for not occupied and '1' for Occupied "<<endl;
    for(i=0;i<row;i++){
        for(int j=0;j<column;j++){
            cout<<"Bench -->    "<<i<<"    Seat -->    "<<j<<endl;
            cin>>input;
            if(input==1||input==0){
                chart[i][j]=input;
            }
            else{
                cout<<"Invalid Input! Seat Empty "<<endl;
            }
        }
    }
    //Printing
    cout<<"Printing the Chart"<<endl;
    for(i=0;i<row;i++){
        cout<<"| ";
        for(int j=0;j<column;j++){
            cout<<chart[i][j]<<" ";
        }
        cout<<" |"<<endl;
    }
    for(i=0;i<row;i++){
            delete [] chart[i];   
        }
    delete [] chart;

    }
