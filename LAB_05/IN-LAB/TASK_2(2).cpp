/*Next, demonstrate indirect recursion by creating two functions, functionA(int n)
and functionB(int n). functionA should call functionB, and functionB
should call functionA, forming a cycle that prints numbers in a specific pattern.
Ensure both programs have a base condition to prevent infinite loops.
*/
#include <iostream>
using namespace std;
void FunctB(int n);
void FunctA(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    FunctB(n-1);
}
void FunctB(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    FunctA(n-1);
}
int main(){
    int num;
    cout<<"Enter a number to print from n down to 1: ";
    cin>>num;
    cout<<"Numbers from "<<num<<" down to 1 --> ";
    FunctA(num);
    cout << endl;
    return 0;
}
