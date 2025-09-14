/* Reverse in Groups of K
   Reverse nodes of a singly linked list in groups of size k.
   Example:
   Input:  1 → 2 → 3 → 4 → 5 → 6 → 7 → 8, k = 3
   Output: 3 → 2 → 1 → 6 → 5 → 4 → 8 → 7
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
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    Node* reverse(Node* head, int k) {
        if (head == nullptr || k <= 1) {
            return head;}
        Node* curr = head;   
        Node* prev = nullptr; 
        Node* next = nullptr; 
        int count = 0;

        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;   
            prev = curr;         
            curr = next;         
            count++;
        }
        if (next != nullptr) {
            head->next = reverse(next, k);
        }
        return prev;
    }
};
int main() {
    SLL list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);
    list.insert(8);
    cout << "Original List"<<endl;
    list.display();
    int k = 3;
    list.head=list.reverse(list.head,k);
    cout << "Reversed in groups of " << k <<endl;
    list.display();
    return 0;
}
