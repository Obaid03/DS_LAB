/*Q2. Create a C++ class named "Exam" using DMA designed to manage student exam records,
complete with a shallow copy implementation? Define attributes such as student name, exam
date, and score within the class, and include methods to set these attributes and display exam
details. As part of this exercise, intentionally omit the implementation of the copy constructor
and copy assignment operator. Afterward, create an instance of the "Exam" class, generate a
shallow copy, and observe any resulting issues?*/

#include <iostream>
#include <cstring>
using namespace std;

class Exam{
    private:
        char* Name;
        char* Date;
        float* Score;
    public:
        Exam(){
            Name=nullptr;
            Date=nullptr;
            Score=nullptr;
        }
        Exam(const char* name,const char* date,float score){
            Name= new char[strlen(name)+1];
            strcpy(Name,name);
            Date= new char[strlen(date)+1];
            strcpy(Date,date);
            Score=new float(score);
        }
        void Display(){
            cout<<"NAME Of Student:   "<<Name<<endl;
            cout<<"Exam Date:      "<<Date<<endl;
            cout<<"Score:      "<<*Score<<endl;
        }
        void Setter(const char* name,const char* date,float score){
            strcpy(Name,name);
            strcpy(Date,date);
            *Score=score;
        }
        ~Exam(){
            delete[] Name; //Both Objects will delete the same memory
            delete[] Date;
            delete Score;
        }

};
int main(){
    Exam E1("OBAID","03 SEP 2005",110);
    E1.Display();
    Exam E2=E1;//Shallow Copy
    E2.Display();
    E1.Setter("Muhammad","29 Feb 2025",89);//Changing the Values of one object will also change the second one aswell(Same Memory)
    E1.Display();
    E2.Display();
}