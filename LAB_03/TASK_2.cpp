/* Merge Two Sorted Singly Linked Lists
   Implement a function to merge two sorted singly linked lists into one sorted list.
   • Example:
     List A: 1 → 3 → 5
     List B: 2 → 4 → 6
     Output: 1 → 2 → 3 → 4 → 5 → 6
   • Bonus: Solve without creating new nodes (rearrange pointers).
*/
#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class SLL{
public:
    Node* head;
    SLL() {
        head = nullptr;
    }
    ~SLL() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insert(int value) {
        Node* n = new Node(value);
        if (head == nullptr) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = n;
    }
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " , ";
            temp = temp->next;
        }
        cout << "NULL"<<endl;
    }
    SLL merge(SLL& other) {
        SLL mergedlist;
        Node* head1 = head;
        Node* head2 = other.head;
        while(head1 != nullptr && head2 != nullptr){
            if(head1->data <= head2->data){
                mergedlist.insert(head1->data);
                head1 = head1->next;}
            else{
                mergedlist.insert(head2->data);
                head2 = head2->next;
            }
        }
        while(head1 != nullptr){
            mergedlist.insert(head1->data);
            head1 = head1->next;
        }
        while (head2 != nullptr){
            mergedlist.insert(head2->data);
            head2 = head2->next;
        }
        return mergedlist;
    }
};
int main(){
    SLL listA, listB,merged;
    listA.insert(1);
    listA.insert(3);
    listA.insert(5);

    listB.insert(2);
    listB.insert(4);
    listB.insert(6);

    cout << "Displaying List A"<<endl;
    listA.display();
    cout << "Displaying List B"<<endl;
    listB.display();
    merged=listA.merge(listB);
    cout << "Displaying Merged List"<<endl;
    merged.display();
    return 0;
}
