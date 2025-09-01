/*Task #7:
A company has multiple departments, each department has a different number of employees.
=> Use a jagged array where each row corresponds to a department and columns store employee
salaries.
Calculate:
-> The highest salary in each department.
-> The department with the overall maximum average salary.*/
#include <iostream>
using namespace std;
int main(){
    int **jagged,*nofEmployees,d,flag,i,j,highest,total;
    double *avg,highAverage;
    cout<<"Enter Number Of Departments"<<endl;
    cin>>d;
    nofEmployees=new int [d];
    avg=new double[d];//making the array of avg
    for(i=0;i<d;i++){
        cout<<"Enter Number of Employee Department "<<i+1<<" Have\t";
        cin>>nofEmployees[i];
    }
    //allocation
    jagged=new int*[d];
    for(i=0;i<d;i++){
        jagged[i]=new int[nofEmployees[i]];
    }
    //input taking
    for(i=0;i<d;i++){
        for(j=0;j<nofEmployees[i];j++){
            cout<<"Enter Salary of Empolyee "<<j+1<<" from Department "<<i+1<<"\t";
            cin>>jagged[i][j];
        }
    }
    //calculating highest in each daprt
    for(i=0;i<d;i++){
        highest=0;
        for(j=0;j<nofEmployees[i];j++){
            if(jagged[i][j]>highest){
                highest=jagged[i][j];
            }
        }
        cout<<"The Highest Salary for Department "<<i+1<<" "<<highest<<endl;
    }
    //calculating highest avg salary depart
    for(i=0;i<d;i++){
        total=0;
        for(j=0;j<nofEmployees[i];j++){
            total+=jagged[i][j];
        }
        avg[i]=(double)(total/nofEmployees[i]);
    }
    highAverage=avg[0];
    flag=0;
    for(i=1;i<d;i++){
        if(avg[i]>highAverage){
            flag=i;
            highAverage=avg[i];
        }
    }
    cout<<"The Highest Average Salary is of Department "<<flag+1<<" "<< "thar is "<<highAverage<<endl;

    for(i=0; i<d; i++) {
        delete[] jagged[i];
    }
    delete[] jagged;
    delete[] nofEmployees;
    delete[] avg;
    
}