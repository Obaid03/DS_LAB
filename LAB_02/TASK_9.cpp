/*Task #9:
Implement a program to represent a sparse matrix using a dynamic 2D array.
=> Input matrix elements.
=> Display the matrix in normal form.
=> Display the matrix in compressed form (row, column, value).*/
#include <iostream>
using namespace std;
int main(){
    int **matrix,i,j,row,column,zerocount=0,nonzerocount=0,flag=0;
    cout<<"Enter Number OF rows in the matrix"<<endl;
    cin>>row;
    cout<<"Enter Number OF columns in the matrix"<<endl;
    cin>>column;
    matrix=new int*[row];
    for(i=0;i<row;i++){
        matrix[i]=new int[column];
    }
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            cout<<"Enter Element at index "<<i<<","<<j<<"\t";
            cin>>matrix[i][j];
        }
    }
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            if(matrix[i][j]==0){
                zerocount++;
            }
            else nonzerocount ++;
        }
    }
    if(zerocount>nonzerocount){
        flag=1;
    }
    //printing
    cout<<"Printing Normal Form"<<endl;
    for(i=0;i<row;i++){
        for(j=0;j<column;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    if(flag){
        cout<<"Printing Reduced Form"<<endl;
        for(i=0;i<row;i++){
            for(j=0;j<column;j++){
                if(!(matrix[i][j]==0)){
                    cout << i << " " << j << " " << matrix[i][j] << endl;
                }
            }
        }

        
        
    }
    else{
        cout<<"Not a sparse Form! cannot write in compressed form"<<endl;
    }

    for(i=0;i<row;i++){
        delete [] matrix[i];
    }
    delete [] matrix;

}
