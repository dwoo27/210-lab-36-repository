#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "IntBinaryTree.h"
using namespace std;

const int SIZE = 20000;

int main() {
    // open the file containing the codes
    ifstream fin;
    fin.open("codes.txt");
    string value;
   
    IntBinaryTree tree; //create BST

    if (fin.good()) { //read values from txt and populate bst
        cout << "file open";
        for (int i = 0; i < SIZE; i++) {
            getline(fin, value);
            tree.insertNode(value);
        }
        fin.close();
    }
    else {
        cout << "File not found";
    }
    //do while for menu
    do {
        cout << "1. Display records" << endl;
        cout << "2. Add record" << endl;
        cout << "3. Delete record" << endl;
        cout << "4. Search for record" << endl;
        cout << "5. Modify record" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter choice: " << endl;
       
        int choice;
        cin >> choice;
        cin.ignore(1000, 10);

        switch (choice) {
            //display bst
            case 1:
                cout << endl;
                cout << "Records in order: " << endl;
                tree.displayInOrder();

            //add to record
            case 2:
                cout << "Enter record to add: " << endl;
                getline(cin, value);

                if (tree.searchNode(value)) {
                    cout << "Record already exists" << endl;
                }
                else {
                    tree.insertNode(value);
                    cout << "Record added: " << value << endl;
                }
                break;

            //delete record
            case 3:
           
            //search for record
            case 4:
           
            //modify record
            case 5:

            //quit
            case 6:
        }

    } while ();
    return 0;
}