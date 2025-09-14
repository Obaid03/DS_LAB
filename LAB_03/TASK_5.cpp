/* Convert Between Linked List Types
   1. Convert a singly linked list into a doubly linked list.
   2. Convert a singly linked list into a circular linked list.
   Demonstrate both conversions with sample input lists.
*/
#include <iostream>
using namespace std;

class SNode{
public:
    int data;
    SNode* next;
    SNode(int val){
        data = val;
        next = nullptr;
    }
};

class DNode{
public:
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class SLL{
public:
    SNode* head;
    SLL(){
        head = nullptr;
    }

    void insert(int value){
        SNode* n = new SNode(value);
        if (head == nullptr) {
            head = n;
            return;
        }
        SNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = n;
    }
    void display(){
        SNode* temp = head;
        while(temp != nullptr){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    DNode* toDLL(){
        if(head == nullptr) return nullptr;

        DNode* dhead = new DNode(head->data);
        DNode* dcurr = dhead;
        SNode* scurr = head->next;

        while(scurr != nullptr){
            DNode* newNode = new DNode(scurr->data);
            dcurr->next = newNode;
            newNode->prev = dcurr;
            dcurr = newNode;
            scurr = scurr->next;
        }

        return dhead;
    }
    SNode* toCSLL(){
        if (head == nullptr) return nullptr;

        SNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = head;
        return head;
    }
};
class DLL{
public:
    DNode* head;
    DLL(DNode* h = nullptr){
        head = h;
    }
    void display() {
        DNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
class CSLL {
public:
    SNode* head;
    CSLL(SNode* h = nullptr) {
        head = h;
    }
    void display(int limit) {
        if (head == nullptr) return;
        SNode* temp = head;
        int count = 0;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
            count++;
        } while (temp != head && count < limit);
        cout << "(back to " << head->data << ")\n";
    }
};

int main() {
    SLL sList;
    sList.insert(1);
    sList.insert(2);
    sList.insert(3);
    sList.insert(4);
    cout << "Singly Linked List: ";
    sList.display();

    DNode* dllHead = sList.toDLL();
    DLL dlist(dllHead);
    cout << "Converted to Doubly Linked List: ";
    dlist.display();

    SNode* csllHead = sList.toCSLL();
    CSLL clist(csllHead);
    cout << "Converted to Circular Linked List: ";
    clist.display(10);

    return 0;
}
