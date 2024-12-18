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

Tree::~Tree() {
    deleteTree(root);
}

void Tree::deleteTree(Node* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void Tree::addNodes(int data) {
    //create Node
    Node *newNode = new Node(data);
    Node *parent = nullptr;
    if(root == nullptr)
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
            parent->left = newNode;
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
        throw std::runtime_error("Node not found");
        //throw "Root Not have Parent";
    }
    if (node == root) {
        throw std::runtime_error("Root node does not have a parent");
    }
    Node* parent = getParent(node);
    if (parent != nullptr) {
        return parent->data;
    }
    throw std::runtime_error("Parent not found");
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
    Node* node = getNodeByData(data);
    if (node == nullptr) {
        throw std::runtime_error("Node not found");
    }

    Node* parent = getParent(node);

    // Case 1: No children
    if (node->left == nullptr && node->right == nullptr) {
        if (parent->left == node) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }
        delete node;
    }
    // Case 2: One child
    else if (node->left == nullptr || node->right == nullptr) {
        Node* child = (node->left != nullptr) ? node->left : node->right;
        if (parent->left == node) {
            parent->left = child;
        } else {
            parent->right = child;
        }
        delete node;
    }
    // Case 3: Two children
    else {
        Node* successor = getMinLeft(node->right);
        int successorData = successor->data;
        Remove(successor->data); // Recursively remove successor
        node->data = successorData;
    }
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

