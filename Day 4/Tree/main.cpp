#include <iostream>
using namespace std;
#include "tree.h"
int main() {
    Tree tree;
    tree.addNodes(50);
    tree.addNodes(30);
    tree.addNodes(70);
    tree.addNodes(20);
    tree.addNodes(40);
    tree.addNodes(60);
    tree.addNodes(80);

    cout << "Tree elements (in-order traversal): ";
    tree.displayAll();
    cout << endl;

    try {
        cout << "Parent of 20: " << tree.getParentByData(20) << endl;
        cout << "Parent of 40: " << tree.getParentByData(40) << endl;
        cout << "Parent of 70: " << tree.getParentByData(70) << endl;
    } catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\nRemoving 20 (leaf node)\n";
    tree.Remove(20);
    cout << "Tree after removing 20: ";
    tree.displayAll();
    cout << endl;

    cout << "\nRemoving 30 (node with one child)\n";
    tree.Remove(30);
    cout << "Tree after removing 30: ";
    tree.displayAll();
    cout << endl;

    cout << "\nRemoving 50 (node with two children)\n";
    tree.Remove(50);
    cout << "Tree after removing 50: ";
    tree.displayAll();
    cout << endl;

    try {
        cout << "\nTrying to find parent of root (60): ";
        cout << tree.getParentByData(60) << endl;
    } catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        cout << "\nTrying to remove a non-existent node (100)\n";
        tree.Remove(100);
    } catch (const std::exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\nFinal tree elements (in-order traversal): ";
    tree.displayAll();
    cout << endl;



    return 0;
}
