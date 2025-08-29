/*sk #3:
Design a program to handle marks of students in different courses using a jagged array
(since each student is enrolled in a different number of courses).
=> Input the number of courses each student takes.
=> Dynamically allocate memory for each student accordingly.
=> Calculate and display each student’s average marks.*/

#include<iostream>
using namespace std;
int main(){
    int *nofcourses;
    int courses;
    int  **jagged;
    cout<<"Enter Total Number Of Courses:   ";
    cin>> courses;
    nofcourses=new int[courses];
    for(int i=0;i<courses;i++){
            cout<<"Enter No of Students in Course  "<<i<<endl;
            cin>>nofcourses[i];
    }
    jagged =new int*[courses];
    for (int i=0;i<courses;i++){
        jagged[i]=new int [nofcourses[i]];
        for(int j=0;j<nofcourses[i];j++){
        cout<<"Enter Marks for course  "<<i<<"  Student "<<j<<endl;
        }
    }

}
