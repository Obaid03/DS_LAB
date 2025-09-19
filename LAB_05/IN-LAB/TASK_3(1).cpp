/*Implement a C++ function sumTail(int n, int total) that calculates the sum
of numbers from 1 to n using tail recursion. The recursive call should be the last
operation in the function.
*/
#include <iostream>
using namespace std;

int Sumtail(int n,int total){
    if(n==0){
        return total;
    }
    total+=n;  
    return Sumtail(n-1,total);
}
int main(){
    int num;
    cout<<"Enter a number to print from n down to 1: ";
    cin>>num;
    cout<<"Numbers from "<<num<<" down to 1 --> ";
    cout<<Sumtail(num,0);
    cout << endl;
    return 0;
}
