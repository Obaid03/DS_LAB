/*Create a program that solves the N-Queens problem for any given N using backtracking. The
program should print all possible solutions for placing N queens on an N x N chessboard so
that no two queens threaten each other. This task requires you to use a recursive function to
place queens row by row , and a validation function to check if a queen can be placed in a
specific cell. If a placement leads to a conflict, the algorithm should backtrack to the previous
row and try a different column.*/
#include <iostream>
using namespace std;

void print(int **board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool issafe(int **board,int n,int row,int col){
    // checking Column Wise
    for(int i=0;i<row;i++){
        if(board[i][col]==1) return false;
    }
    // Checking left diaogonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(board[i][j]==1) return false;
    }
    // Checking right diaogonal
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(board[i][j]==1) return false;
    }
    return true;
}

void nQueenssolve(int **board,int n,int row){
    if(row==n){
        print(board,n);
        return;
    }
    for(int col=0;col<n;col++){
        if(issafe(board,n,row,col)){
            board[row][col]=1;
            nQueenssolve(board,n,row+1);
            board[row][col]=0;
        }
    }
}

int main(){
    int n;
    cout<<"Enter N: ";
    cin>>n;
    int **board=new int*[n];
    for(int i=0;i<n;i++){
        board[i]=new int[n];
        for(int j=0;j<n;j++) board[i][j]=0;
    }
    cout<<"All solutions for "<<n<<" Queens\n";
    nQueenssolve(board,n,0);
    for(int i=0;i<n;i++) delete[] board[i];
    delete[] board;
    return 0;
}