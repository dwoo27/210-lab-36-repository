#include <iostream>
#include <fstream>
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

        switch (choice) {
            //display bst
            case 1:
        
            //add to record
            case 2:
            
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