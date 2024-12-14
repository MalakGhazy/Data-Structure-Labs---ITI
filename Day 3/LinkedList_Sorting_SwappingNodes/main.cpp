#include <iostream>
using namespace std;

class Exception
{
public:
    int code;
    const char *name;
    Exception(int _code , const char* _name)
    {
        code=_code;
        name=_name;
    }
};
class Node{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int _data)
    {
        data=_data;
        prev= nullptr;
        next = nullptr;
    }
};
class LinkedList{
public:
    Node *head;
    Node *tail;
    LinkedList()
    {
        head = tail = nullptr;
    }
    void addNode(int _data)
    {
        Node *newNode = new Node(_data);
        if(head == nullptr)
        {
            head=tail=newNode;
            return;
        }
        tail->next=newNode;
        newNode->prev = tail;
        tail=newNode;
    }

    void Remove(Node *node){
        if(node== nullptr){
            cout<<"Not Found "<<endl;
            return ;
        }
        if(node->prev != nullptr)
        {
            node->prev->next = node->next;
        }
        else
        {
            head = node->next;
        }
        if(node->next != nullptr)
        {
            node->next->prev = node->prev;
        }
        else
        {
            tail = node->prev;
        }
        node->next = nullptr;
        node->prev = nullptr;
    }
    void InsertAfter(Node *node2, Node *afternode1)
    {
        if(node2 == nullptr || afternode1== nullptr)
        {
            return;
        }
        node2->prev = afternode1;
        node2->next = afternode1->next;
        //Case 1: there is a node next to node1 (afterNode1)
            if(afternode1->next != nullptr)
            {
                afternode1->next->prev = node2;
            }
            //Case 2: node1 (afterNode1) is a tail
            if(afternode1 == tail)
            {
                tail = node2;
            }
            afternode1->next = node2;
    }
    void swapNodes(Node *node1,Node *node2)
    {
        if (node1 == nullptr || node2 == nullptr || node1 == node2) {
            return;
        }

        if (node1->next != node2) {
            cout << "Swap is only implemented for adjacent nodes!" << endl;
            return;
        }

        Remove(node1);
        InsertAfter(node1,node2);
    }
    void bubbleSort()
    {
        if (head == nullptr || head->next == nullptr)
        {
            throw Exception(101,"Linked List Is Empty");
        }
        int sorted = 0;
        while (sorted == 0)
        {
            sorted=1;
            Node *current = head;
            while (current->next!= nullptr)
            {
                if(current->data > current->next->data)
                {
                    swapNodes(current,current->next);
                    sorted=0;
                }
                current = current->next;
            }
        }
    }



    void display()
    {
        Node *current = head;
        if(current == nullptr)
        {
            cout << "Empty Linked List .\n";
        }
        while(current!= nullptr)
        {
            cout << current->data <<"\t";
            current = current->next;
        }

    }
private:
    //Helper Function
    Node * GetNode(int _data){
        Node *current=head;
        while(current != nullptr ){
            if(current->data == _data){
                return current;
            }
            current=current->next;
        }
        return nullptr;
    }

};
int main() {
    LinkedList ls;
    ls.addNode(50);
    ls.addNode(60);
    ls.addNode(10);
    ls.addNode(40);
    ls.addNode(90);
    cout << "Original List: ";
    ls.display();

    ls.bubbleSort();
    cout << "\nSorted List:   ";
    ls.display();
    return 0;
}
