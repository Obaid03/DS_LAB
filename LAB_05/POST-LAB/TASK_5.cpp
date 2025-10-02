/*Implement a Sudoku solver using the backtracking technique. The program should take a
partially filled 9x9 Sudoku grid and fill the empty cells (represented by 0) to solve the puzzle.
Your algorithm should:
1. Find an empty cell.
2. Try placing a number from 1 to 9 in the empty cell.
3. Check if the number is valid in the current row, column, and 3x3 subgrid.
4. If valid, recursively call the function to solve the rest of the puzzle.
5. If the recursive call doesn't lead to a solution,
backtrack by resetting the cell to 0 and trying the next number.*/
#include <iostream>
using namespace std;

void print(int a[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool issafe(int a[9][9],int r,int c,int x){
    for(int j=0;j<9;j++)
        if(a[r][j]==x) return false;
    for(int j=0;j<9;j++)
        if(a[j][c]==x) return false;
    int sr=r-r%3,sc=c-c%3;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(a[sr+i][sc+j]==x) return false;
    return true;
}

bool solve(int a[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(a[i][j]==0){
                for(int x=1;x<=9;x++){
                    if(issafe(a,i,j,x)){
                        a[i][j]=x;
                        if(solve(a)) return true;
                        a[i][j]=0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    int a[9][9]={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    if(solve(a)) print(a);
    else cout<<"No solution exists!";
    return 0;
}