/* Flatten a Multilevel Linked List
   Each node has:
   - next pointer (normal linked list connection).
   - child pointer (points to another linked list).
   Flatten so that all nodes appear in a single-level list.

   Example:
   1 -> 2 -> 3
        |
        4 -> 5
   Output: 1 -> 2 -> 4 -> 5 -> 3
*/
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int val) {
        data = val;
        next = nullptr;
        child = nullptr;
    }
};

class MLL {
public:
    Node* head;
    MLL() {
        head = nullptr;
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
    void display(Node* h) {
        Node* temp = h;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    Node* flatten(Node* h) {
        if (h == nullptr) return nullptr;

        Node* curr = h;
        while (curr != nullptr) {
            if (curr->child != nullptr) {
                Node* nxt = curr->next;

                Node* childList = flatten(curr->child);
                curr->next = childList;
                Node* temp = childList;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = nxt;
                curr->child = nullptr;
            }
            curr = curr->next;
        }
        return h;
    }
};

int main() {
    MLL list;
    list.insert(1);
    list.insert(2);
    list.insert(3);

    Node* temp = list.head->next;
    temp->child = new Node(4);
    temp->child->next = new Node(5);

    cout << "Flattened List: ";
    Node* flatHead = list.flatten(list.head);
    list.display(flatHead);

    return 0;
}
