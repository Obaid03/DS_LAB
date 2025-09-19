/* Write a simple C++ program that demonstrates direct recursion. Create a function
printNumbers(int n) that prints numbers from n down to 1 by calling itself
directly*/

#include <iostream>
using namespace std;

void print(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    print(n-1);
}

int main(){
    int num;
    cout<<"Enter a number to print from n down to 1: ";
    cin>>num;
    
    cout<<"Numbers from "<<num<<" down to 1 --> ";
    print(num);
    cout << endl;
    return 0;
}
