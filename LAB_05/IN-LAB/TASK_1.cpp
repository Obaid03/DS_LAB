/*Write a recursive C++ function calculateFactorial(int n) that computes the factorial
of a given integer n . The function should have a base condition to stop the recursion when n is
0 or 1, and should call itself with a smaller value of n (e.g., n-1) to solve the problem.
*/
#include <iostream>
using namespace std;
int Factorial(int num){
    if(num==0 || num==1){
        return 1;
    }
    return num*(Factorial(num-1));
}
int main(){
    int factorial,num;
    cout<<"Enter the Number You want to find the factorial of"<<endl;
    cin>>num;
    factorial=Factorial(num);
    cout<<"Factorial of "<<num<<" is "<<factorial<<endl;
}
