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

    if (fin.good()) {
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

    //test tree sucessfully imported
    tree.displayInOrder();

    return 0;
}