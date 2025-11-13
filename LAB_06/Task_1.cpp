#include <iostream>
using namespace std;
class MyStack{
    int* array;
    int top;
    int size;
    public:
        MyStack(int s){
            top=-1;
            array = new int (s);
            size=s;
        }
        void push(int data){
            if(top==size-1){
                cout<<"Stack OverFlow"<<endl;
                return;
            }
            array[++top]=data;
        }
        int pop(){
            if(top==-1){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            return array[top--];
        }
        int peek(){
            if(top==-1){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            return array[top];
        }
        void Display(){
             for(int i=top; i >= 0; i--) {
            cout << i << "->" << array[i] << endl;
        }
        }
};
int main(){
    MyStack S(5);
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    cout<<"Displaying After Pushing Data"<<endl;
    S.Display();
    S.pop();
    S.pop();
    S.peek();
    cout<<"Displaying After Popping Data"<<endl;
    S.Display();
}