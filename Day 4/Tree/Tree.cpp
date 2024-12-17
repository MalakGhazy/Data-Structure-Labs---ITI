//
// Created by pc king on 12/16/2024.
//

#include "Tree.h"
Tree::Tree() {
    root= nullptr;
}

void Tree::addNodes(int data) {
    //create Node
    Node *newNode = new Node(data);
    Node *parent = nullptr;
    if(root = nullptr)
    {
        root=newNode;
    }
    else
    {
        Node *current = root;
        while (current != nullptr)
        {
            parent = current;
            if(data > current->data)
            {
                current = current->right; // Null
            }
            else
            {
                current = current->left ;
            }
        }
        if(data > parent->data)
        {
            parent->right = newNode;
        } else
        {
            current->left = newNode;
        }
    }

}

Node *Tree::getNodeByData(int data) {

}

int Tree::getParentByData(int data) {

}

Node *Tree::getParent(Node *node) {

}

Node *Tree::getMaxRight(Node *node) {

}

Node *Tree::getMinLeft(Node *node) {

}

void Tree::Remove(int data) {

}

void Tree::display(Node *node) {

}

void Tree::displayAll() {

}

