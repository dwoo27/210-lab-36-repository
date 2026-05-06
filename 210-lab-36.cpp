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
    int choice;

    do {
        cout << "1. Display records" << endl;
        cout << "2. Add record" << endl;
        cout << "3. Delete record" << endl;
        cout << "4. Search for record" << endl;
        cout << "5. Modify record" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter choice: " << endl;
       
     
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
                cout << "Enter record to delete: " << endl;
                getline(cin, value);

                if (tree.searchNode(value)) {
                    cout << "Record deleted: " << value << endl;
                    tree.remove(value);
                }
                else {
                    cout << "Record not found: " << value << endl;
                }
                break;


            //search for record
            case 4:
                cout << "Enter record to search: " << endl;
                getline(cin, value);

                if (tree.searchNode(value)) {
                    cout << "Record found" << endl;
                }
                else {
                    cout << "Record not found" << endl;
                }
                break;

            //modify record
            case 5:
                string newValue;

                cout << "Enter record to modify: " << endl;
                getline(cin, value);

                cout << "Enter new record: " << endl;
                getline(cin, newValue);

                if (!tree.searchNode(value)) {
                    cout << "Record to modify not found" << endl;
                }
                if (tree.searchNode(newValue)) {
                    cout << "New record already exists" << endl;
                }
                else {
                    cout << "Record found: " << value << endl;
                    cout << "Changing record to " << newValue << endl;
                    tree.remove(value);
                    tree.insertNode(newValue);
                }
                break;
            //quit
            case 6:
                cout << "Exiting program" << endl;
                break;
        }

    } while (choice != 6);
    return 0;
}