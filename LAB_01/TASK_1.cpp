/*Q1. Suppose you are developing a bank account management system, and you have defined the
BankAccount class with the required constructors. You need to demonstrate the use of these
constructors in various scenarios.
1. Default Constructor Usage: Create a default-initialized BankAccount object named
account1. Print out the balance of account1.
2. Parameterized Constructor Usage: Create a BankAccount object named account2 with
an initial balance of $1000. Print out the balance of account2.
3. Copy Constructor Usage: Using the account2 you created earlier, create a new
BankAccount object named account3 using the copy constructor. Deduct $200 from
account3 and print out its balance. Also, print out the balance of account2 to ensure it
hasn't been affected by the transaction involving account3.*/

#include <iostream>
using namespace std;
class BankAccount{
    private:
        double Bal;
    public: 
        BankAccount(){
            Bal=0;
        }
        BankAccount(double bal):Bal(bal){}
        BankAccount(const BankAccount &acc){
            Bal=acc.Bal;
        }
        void Display (){
            cout<<"Balance is -->   "<<Bal<<endl;
        }
        void Deduct(double amount){
            if(amount<=Bal){
                Bal-=amount;
            }
            else cout<<"Invalid Amount Entered."<<endl;
        }
};
int main(){
    BankAccount Account1;
    cout<<"Account 1 -->\t";
    Account1.Display();
    BankAccount Account2(1000);
    cout<<"Account 2 -->\t";
    Account2.Display();
    // BankAccount Account3=Account2; //Can be done directly(Complier Provided) since Pointers/DMA not Used
    BankAccount Account3(Account2);
    Account3.Deduct(200);
    cout<<"Account 3 -->\t";
    Account3.Display();
    cout<<"Account 2 -->\t";
    Account2.Display();
    
}