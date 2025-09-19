/*Implement another function sumNonTail(int n) that calculates the same sum
using non-tail recursion. This function should perform an operation (e.g., addition) after
the recursive call returns. Compare the two implementations and explain the difference
in their call stacks.
*/
#include <iostream>
using namespace std;

int SumNontail(int n){
    if(n==0){
        return n;
    }
    return n+SumNontail(n-1);
}

int main(){
    int num;
    cout<<"Enter a number to print from n down to 1: ";
    cin>>num;
    cout<<"Sum from 1 to "<<num<<" --> ";
    cout<<SumNontail(num);
    return 0;
}
