#include <iostream>
using namespace std;
class Node{
public:
    Node *right;
    Node *left;
    int data;
    Node(int _data)
    {
        data = _data;
        right= nullptr;
        left= nullptr;
    }
};
class Tree
{
public:
    Node *root;
    Tree();
    void addNode()
    {

    }
    void Remove(int data)
    {

    }
    void display()
    {

    }
    // get data by parent
    // get data by node
    // find max node
    // find min node
    //Bonus -> MaxDepth
private:
    //Helper Functions

};
int main() {
    cout << "Hello, World!" << endl;
    return 0;
}
