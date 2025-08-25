/*Q3. Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the
Rule of Three by defining a destructor, copy constructor, and copy assignment operator.
Demonstrate the behavior of both shallow and deep copy using test cases.*/
#include <iostream>
using namespace std;

class Box{
    private:
        int* sides;
    
    public:
        Box(){
            sides=nullptr;
        }
        Box(int s){
            sides=new int(s);
        }
        Box(const Box &b1){
            sides=new int (*(b1.sides));
        }
        Box& operator=(const Box& b1){
            delete sides;
            sides= new int (*(b1.sides));
            return *this;
        }
        ~Box(){
            delete sides;
        }
        void Display(){
            cout<<"Length of the Sides Is:  "<<*sides<<endl;
        }
        void SetSide(int n){
            delete sides;
            sides=new int(n);
        }

};
int main(){
    Box B1,B2(10);
    cout<<"Displaying Sides Of Box 2:   ";
    B2.Display();
    cout<<"Assigning Box 2 To Box 1 (Assignment)"<<endl;
    B1=B2;//Deep Copy Assignment
    cout<<"Displaying Sides Of Box 1:   ";
    B1.Display();
    cout<<"Displaying Sides Of Box 2:   ";
    B2.Display();
    cout<<"Changing Sides Of Box 1 :    ";
    B1.SetSide(20);
    B1.Display();
    cout<<"Displaying Sides Of Box 2:   ";
    B2.Display();
    cout<<"Creating Box 3 (Copy Constructor)"<<endl;
    Box B3(B2);
    cout<<"Displaying Sides Of Box 3:   ";
    B3.Display();



}