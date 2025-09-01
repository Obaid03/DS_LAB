/*
Task #10:
Design a program that maintains library book records using dynamic arrays.
=> Each row represents a category (e.g., Fiction, Science, History).
=> Each category has a different number of books (use a jagged array).
=> Store book IDs dynamically and allow the user to search for a given book ID.
=> Print whether the book is available and in which category.*/
#include <iostream>
using namespace std;

int main() {
    int categories,** library,* nofbook;
    cout << "Enter number of categories\t";
    cin >> categories;

    library = new int*[categories];
    nofbook = new int[categories];

    for (int i = 0; i < categories; i++) {
        cout << "Enter number of books in category " << i + 1 << "\t";
        cin >> nofbook[i];

        library[i] = new int[nofbook[i]];

        cout << "Enter Book IDs for category " << i + 1 <<endl;
        for (int j = 0; j < nofbook[i]; j++) {
            cin >> library[i][j];
        }
    }

    int search;
    bool flag = false;
    cout << "Enter Book ID to search\t";
    cin >> search;

    for (int i = 0; i < categories; i++) {
        for (int j = 0; j < nofbook[i]; j++) {
            if (library[i][j] == search) {
                cout << "Book " << search << " found in category " << i + 1 << endl;
                flag = true;
                break;
            }
        }
        if (flag) break;
    }

    if (!flag) {
        cout << "Book " << search << " not available." << endl;
    }

    
    for (int i = 0; i < categories; i++) {
        delete[] library[i];
    }
    delete[] library;
    delete[] nofbook;

    return 0;
}
