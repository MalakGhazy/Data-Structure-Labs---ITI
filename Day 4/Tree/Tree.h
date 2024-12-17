//
// Created by pc king on 12/16/2024.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H
#include "Node.h"

class Tree{
public:
    Node *root;
    Tree();
    void addNodes(int data);
    int getParentByData(int data);
    void Remove(int data);
    void displayAll();
private:
    Node *getNodeByData(int data);
    Node *getParent(Node *node);
    Node *getMaxRight(Node *node);
    Node *getMinLeft(Node *node);
    void display(Node *node);
};


#endif //TREE_TREE_H
