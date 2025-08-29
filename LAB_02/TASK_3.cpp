/*sk #3:
Design a program to handle marks of students in different courses using a jagged array
(since each student is enrolled in a different number of courses).
=> Input the number of courses each student takes.
=> Dynamically allocate memory for each student accordingly.
=> Calculate and display each student’s average marks.*/

#include<iostream>
using namespace std;
int main(){
    int *nofstudents;
    int students;
    int  **jagged;
    cout<<"Enter Total Number Of students:   ";
    cin>> students;
    nofstudents=new int[students];
    for(int i=0;i<students;i++){
            cout<<"Enter No of courses students   "<<i<<"have"<<endl;
            cin>>nofstudents[i];
    }
    jagged =new int*[students];
    for (int i=0;i<students;i++){
        jagged[i]=new int [nofstudents[i]];
        for(int j=0;j<nofstudents[i];j++){
            cout<<"Enter Marks for Student  "<<j<<"  Course "<<i<<endl;
            cin>>jagged[i][j];
        }
    }
    int sum;
    for(int i=0;i<students;i++){
        sum=0;
        for(int j=0;j<nofstudents[i];j++){
            sum+=nofstudents[i][j];
        }
        cout<<"Average for student  "<<i<<" is  "<<sum<<endl;
    }
    
}
