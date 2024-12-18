//
// Created by pc king on 12/16/2024.
//
#include "Tree.h"
#include <iostream>
using namespace std;

#include <iostream>

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
    Node *current = root;
    while (current != nullptr) {
        if(data == current->data) {
            return current;
        }
        else if (data > current->data) {
            current = current->right;
        }
        else {
            current = current->left ;
        }
    }
    return nullptr;
}

int Tree::getParentByData(int data) {
    Node *node = getNodeByData(data);
    if (node == nullptr) {
        throw "Root Not have Parent";
    }
    if (node!=nullptr) {
        Node *res = getParent(node);
        if (res!=nullptr) {
            return res->data;
        }
    }
    throw "Not Found";

}

Node *Tree::getParent(Node *node) {
    Node *parent = root;
    while (parent != nullptr) {
        if (parent->left == node || parent->right == node) {
            return parent;
        }
        else if(node->data > parent->data) {
            parent = parent->right;
        }
        else {
            parent = parent->left;
        }
    }
    return nullptr;
}

Node *Tree::getMaxRight(Node *node) {
    Node* current = node;
    while (current ->right != nullptr) {
        current = current->right;
    }
    return current;
}

Node *Tree::getMinLeft(Node *node) {
    Node *current = node;
    while (current ->left != nullptr) {
        current = current->left;
    }
    return current;
}

void Tree::Remove(int data) {

}

void Tree::display(Node *node) {
    if (node == nullptr) {
        return;
    }
    display(node->left);
    cout << node->data << " ";
    display(node->right);

}

void Tree::displayAll() {
    display(root);

}

