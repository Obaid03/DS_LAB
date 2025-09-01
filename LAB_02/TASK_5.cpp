/*Task #5:
Write a C++ program that dynamically creates a 2D matrix and provides:
=> Addition of two matrices.
=> Subtraction of two matrices.
=> Ensure safe memory handling with proper allocation/deallocation.*/
#include<iostream>
using namespace std;
void subtract(double **mat1,double **mat2,int m, int n){
    double **result=new double*[m];
    for(int i=0;i<m;i++){
        result[i]=new double [n];}
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result[i][j]=mat1[i][j]-mat2[i][j];
            }
        }
        //printing
        cout<<endl<<"Subtraction Results"<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
        //deleting
        for(int i=0;i<m;i++){
                delete [] result[i];
        }
        delete[] result;
}
void Add(double **mat1,double **mat2,int m, int n){
    double **result=new double*[m];
    for(int i=0;i<m;i++){
        result[i]=new double [n];}
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result[i][j]=mat1[i][j]+mat2[i][j];
            }
        }
        //printing
        cout<<endl<<"Addition Results"<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<result[i][j]<<" ";
            }
            cout<<endl;
        }
        //deleting
        for(int i=0;i<m;i++){
                delete [] result[i];
        }
        delete[] result;
}
int main(){
    int r,c,m,n,i,j;
    double **mat1,**mat2;
    cout<<"Enter Number of rows for Matrix one\t";
    cin>>r;
    cout<<"Enter Number of columns for Matrix one\t";
    cin>>c;
    mat1=new double*[r];
    for(i=0;i<r;i++){
        mat1[i]=new double[c];
    }
    cout<<"Enter values for Matrix One"<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<"Enter value at index "<<i<<","<<j<<"\t";
            cin>>mat1[i][j];
        }
    }
    cout<<endl<<"Order Of the Matrix should be same"<<endl<<endl;
    while(true){
        
        cout<<"Enter Number of rows for Matrix Two\t";
    cin>>m;
    cout<<"Enter Number of columns for Matrix Two\t";
    cin>>n;
    if((r==m&&c==n)){
        break;
    }
    cout<<"Order is not same! try again";
    }
    mat2=new double*[m];
    for(i=0;i<m;i++){
        mat2[i]=new double[n];
    }
    cout<<"Enter values for Matrix Two"<<endl;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cout<<"Enter value at index "<<i<<","<<j<<"\t";
            cin>>mat2[i][j];
        }
    }
    cout<<endl<<"Performing Subtraction"<<endl;
    subtract(mat1,mat2,m,n);
    cout<<endl<<"Performing Additon"<<endl;
    Add(mat1,mat2,m,n);

    for(i=0;i<m;i++){
        delete [] mat1[i];
}
        delete[] mat1;
    for(i=0;i<m;i++){
        delete [] mat2[i];
}
        delete[] mat2;
}