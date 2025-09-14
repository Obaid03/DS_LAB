/* Josephus Problem using Circular Linked List
   N people stand in a circle, eliminating every k-th person until one survives.
   Example:
   Input: N = 7, k = 3
   Output: Survivor = 4
*/
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class CLL {
public:
    Node* head;
    CLL() {
        head = nullptr;
    }
    ~CLL() {
        if (head == nullptr) return;
        Node* temp = head->next;
        while (temp != head) {
            Node* del = temp;
            temp = temp->next;
            delete del;
        }
        delete head;
    }
    void insert(int value) {
        Node* n = new Node(value);
        if (head == nullptr) {
            head = n;
            n->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
    }
    void display() {
        if (head == nullptr) return;
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to " << head->data << ")\n";
    }
    int josephus(int k) {
        if (head == nullptr || k <= 0) {
            return -1;
        }
        Node* prev = nullptr;
        Node* curr = head;
        while (curr->next != curr) {
            for (int count = 1; count < k; count++) {
                prev = curr;
                curr = curr->next;
            }
            cout << "Eliminated: " << curr->data << endl;
            prev->next = curr->next;
            if (curr == head) {
                head = curr->next;
            }
            delete curr;
            curr = prev->next;
        }
        return curr->data; 
    }
};
int main() {
    int N = 7, k = 3;
    CLL circle;
    circle.insert(1);
    circle.insert(2);
    circle.insert(3);
    circle.insert(4);
    circle.insert(5);
    circle.insert(6);
    circle.insert(7);
    
    cout << "Initial Circle"<<endl;
    circle.display();
    int survivor = circle.josephus(k);
    cout << "Survivor --> " << survivor << endl;
    return 0;
}
