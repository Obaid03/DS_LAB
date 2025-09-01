/*Task #6:
Implement a Safe Pointer class to wrap around an integer pointer.
=> Provide methods for setValue(), getValue(), and release().
=>
Demonstrate the class by storing marks of 5 students and printing them safely without
direct pointer manipulation.*/
#include <iostream>
using namespace std;
class Marks{
    private:
        int *marks;
    public:
        Marks(){
            marks=nullptr;
        }
        Marks(int m){
            marks=new int(m);
        }
        void SetValue(int m){
            if(marks==nullptr){
                marks=new int(m);
            }
            *marks=m;
        }
        int GetValue(){
            if(marks==nullptr){
                cout<<"Its a Null Pointer"<<endl;
                return 0;
            }
            return *marks;
        }
        ~Marks(){
            if(!(marks==nullptr)){
                delete marks;
                marks =nullptr;
            }
        }
};
int main(){
    int m;
    Marks mark[5];
    for(int i=0;i<5;i++){
        cout<<"Enter Marks for Student "<<i+1<<"\t";
        cin>>m;
        mark[i].SetValue(m);
    }
    cout<<"Printing the Results"<<endl;
    for(int i=0;i<5;i++){
        cout<<"Marks for Student "<<i+1<<" --> "<<mark[i].GetValue()<<endl;;
    }
}