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
    void swap(Node *node1,Node *node2)
    {
        int temp = node1 ->data;
        node1->data = node2->data;
        node2->data = temp;
    }
    void bubbleSort()
    {
        if (head == nullptr || head->next == nullptr)
        {
            throw Exception(101,"Linked List Is Empty");
        }
        /*int sorted=0;
        do {
            sorted = 1;
            Node *current = head;

            while (current->next != nullptr) {
                if (current->data > current->next->data) {
                    swap(current, current->next);
                    sorted = 0;
                }
                current = current->next;
            }
        } while (!sorted);*/

        int sorted = 0;
        while (sorted == 0)
        {
            sorted=1;
            Node *current = head;
            while (current->next!= nullptr)
            {
                if(current->data > current->next->data)
                {
                    swap(current,current->next);
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
            cout<< current->data <<"   ";
            current = current->next;
        }
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
