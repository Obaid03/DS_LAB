/*Task #8:
Create a dynamic program to store temperature readings of a city for n days and m different times 
in a day using a 2D array.
=> Calculate the daily average temperature.
=> Find the hottest and coldest day.*/


//I have calculated Hottest And Coldest day using individual Temperature not average.


#include <iostream>
using namespace std;
int main(){
    int i,j,d,t,flag;
    double **temp,avg,hot,cold,total;
    cout<<"Enter Number of Days:"<<endl;
    cin>>d;
    cout<<"Enter Number of Times:"<<endl;
    cin>>t;
    temp=new double*[d];
    for(i=0;i<d;i++){
        temp[i]=new double[t];
    }
    //taking Input
    for(i=0;i<d;i++){
        for(j=0;j<t;j++){
            cout<<"Enter Temp at Day "<<i+1<<" At Time "<<j+1<<"\t";
            cin>>temp[i][j];
        }
    }
    //Calculating Avg
    flag=0;
    for(i=0;i<d;i++){
        total=0.0,avg=0.0;
        for(j=0;j<t;j++){
            total+=temp[i][j];
        }
        avg=total/t;
        cout<<"The Average Temp for Day "<<i+1<<" is "<<avg<<endl;
    }
    //Calculating coldest
    cold=temp[0][0];
    for(i=0;i<d;i++){
        for(j=0;j<t;j++){
            if(temp[i][j]<cold){
                cold=temp[i][j];
                flag=i;
            }
        }
    }
    cout<<"The Coldest Day is "<<flag+1<<" "<< "that is "<<cold<<endl;

    //Calculating hottest
    hot=temp[0][0];
    flag=0;
    for(i=0;i<d;i++){
        for(j=0;j<t;j++){
            if(temp[i][j]>hot){
                hot=temp[i][j];
                flag=i;
            }
        }
        
    }
    cout<<"The hottest Day is "<<flag+1<<" "<< "that is "<<hot<<endl;

    for (i = 0; i < d; i++) {
        delete[] temp[i];
    }
    delete[] temp;
}