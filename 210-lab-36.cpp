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
    string newValue;
    bool proceed;

    do {
        cout << "1. Display records" << endl;
        cout << "2. Add record" << endl;
        cout << "3. Delete record" << endl;
        cout << "4. Search for record" << endl;
        cout << "5. Modify record" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter choice: " << endl;
       
     
        cin >> choice;
        
        if (cin.fail()) {//prevents program from crashing if cin receives str instead of int for invalid choice
            cin.clear();
            choice = 0;
        }
        
        cin.ignore(1000, 10);

        switch (choice) {
            //display bst
            case 1:
                cout << endl;
                cout << "Records in order: " << endl;
                tree.displayInOrder(); //displays sorted bst
                cout << endl;
                break;

            //add to record
            case 2:
                cout << "Enter record to add: " << endl;
                getline(cin, value);

                if (tree.searchNode(value)) { //searches if new record to be added already exists
                    cout << "Record already exists" << endl << endl;
                }
                else {
                    tree.insertNode(value); //otherwise add new record
                    cout << "Record added: " << value << endl << endl;                
                }
                break;

            //delete record
            case 3:
                cout << "Enter record to delete: " << endl;
                getline(cin, value);

                if (tree.searchNode(value)) { //checks if record exists then deletes 
                    cout << "Record deleted: " << value << endl << endl;
                    tree.remove(value);
                }
                else {
                    cout << "Record not found: " << value << endl << endl;
                }
                break;


            //search for record
            case 4:
                cout << "Enter record to search: " << endl;
                getline(cin, value);

                if (tree.searchNode(value)) { //searches for record
                    cout << "Record found" << endl << endl;
                }
                else {
                    cout << "Record not found" << endl << endl;
                }
                break;

            //modify record
            case 5:
                cout << "Enter record to modify: " << endl; 
                getline(cin, value);

                cout << "Enter new record: " << endl;
                getline(cin, newValue);

                proceed = true;

                if (!tree.searchNode(value)) { //checks if record to change exists
                    cout << "Record to modify not found" << endl;
                    proceed = false;
                }
                if (tree.searchNode(newValue)) { //checks if new record already exists
                    cout << "New record already exists" << endl;
                    proceed = false;
                }
                if(proceed){ //removes old and adds new records
                    cout << endl << "Record found: " << value << endl;
                    cout << "Changing record to: " << newValue << endl << endl;
                    tree.remove(value);
                    tree.insertNode(newValue);
                }
                break;
           
            //quit
            case 6:
                cout << "Exiting program" << endl;
                break;
            
            default: //default for invalid choice
                cout << "Invalid choice. Please try again." << endl << endl;
                break;
        }

    } while (choice != 6);
   
    return 0;
}