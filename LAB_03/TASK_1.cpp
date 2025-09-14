/*1. Palindrome Check in Singly Linked List
Write a program to check if a singly linked list is a palindrome.
• Input: A singly linked list of integers.
• Output: true if the list reads the same forward and backward, false otherwise.
*/
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
        Node *next;
        Node(int val){
            data=val;
            next=nullptr;
        }};
class SLL{
    public:
    Node* head;
    SLL(){
        head=nullptr;
    }
    ~SLL() {
        Node* temp;
        while (head!=nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }}
    void insert(int value) {
        Node* n= new Node(value);
        if (head==nullptr) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }
    void display() {
        Node* temp = head;
        while (temp!=nullptr) {
            cout << temp->data << " , ";
            temp = temp->next;}
        cout << "NULL\n";}
    void check() {
        if (head==nullptr|| head->next==nullptr){
            cout<<"List is a Palindrome"<<endl;
            return;}
        int count = 0;
        Node* temp = head;
        while(temp!=nullptr){
            count++;
            temp = temp->next;}
        int* arr = new int[count];
        temp = head;
        for(int i = 0; i < count; i++){
            arr[i] = temp->data;
            temp = temp->next;}
        bool flag = true;
        int j=count-1;
        for(int i = 0; i < count/2; i++){
            if (arr[i] != arr[j]){
                flag = false;
                break;
            }j--;}
        if(flag){
            cout << "Lsit is A Palindrome"<<endl;}
        else cout << "Lsit is not A Palindrome"<<endl; 
        delete[] arr;
        return;
    }
};
int main(){
    SLL list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(2);
    list.insert(1);
    cout <<"Displaying Linked List"<<endl;
    list.display();
    list.check();
}