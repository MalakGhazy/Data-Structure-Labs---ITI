#include <iostream>
using namespace std;
//stack using linkedlist
// push - pop - peek - display

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
    Node(int _data){
        data = _data;
        prev = nullptr;
    }
};
////////////////////////////////////////
class StackLinkedList
{
    Node *tail;
public:
    StackLinkedList()
    {
        tail = nullptr;
    }
// push
    void push(int data)
    {
        Node *newNode = new Node(data);
     // the previous pointer to the newNode will be the old tail
        newNode ->prev = tail;
     // update the current tail to newNode;
        tail = newNode;
    }
////////////////////////////////////////////////
//pop
    void pop (int &data)
    {
        if (tail == nullptr) {
            throw Exception (101,"Stack Is Empty");
        }
        Node *temp = tail;

        data = temp-> data;

        tail = tail -> prev;

        delete temp;
        //return data;
    }
//////////////////////////////////////
//peek --> Show the top element without deleting
    void peek(int &data)
    {
        if(tail == nullptr)
        {
            throw Exception (101,"Stack Is Empty");
        }
        data = tail-> data;
    }

/////////////////////////////////////
//display
    void display()
    {
        if(tail == nullptr)
        {
            cout << "Stack is Empty" << endl;
            return;        }
        Node *current = tail;
        while(current != nullptr)
        {
            cout << current-> data <<"\t";
            current = current-> prev;
        }
        cout <<endl;
    }

};
int main() {
    StackLinkedList ls;
    ls.push(10);
    ls.push(20);
    ls.push(30);
    ls.display();

    int data;
    // Peek the top element ---> 30
    try {
        int topElement;
        ls.peek(topElement);
        cout << "Peeked Value: " << topElement << endl;
    } catch (const Exception& e) {
        cout << e.name << endl;
    }
    try{
        ls.pop(data);
        cout << "Popped Value: " << data << endl;
    }catch (const Exception& e){
        cout <<e.name<< endl;
    }
    ls.display();
    // Peek the top element ---> 20
    try {
        int topElement;
        ls.peek(topElement);
        cout << "Peeked Value: " << topElement << endl;
    } catch (const Exception& e) {
        cout << e.name << endl;
    }

    try{
        ls.pop(data);
        cout << "Popped Value: " << data << endl;
    }catch (Exception e){
        cout <<e.name<< endl;
    }
    ls.display();
    // Peek the top element ---> 10

    try {
        int topElement;
        ls.peek(topElement);
        cout << "Peeked Value: " << topElement << endl;
    } catch (const Exception& e) {
        cout << e.name << endl;
    }


    try{
        ls.pop(data);
        cout << "Popped Value: " << data << endl;
    }catch (Exception e){
    cout <<e.name<< endl;}
    ls.display();
cout << "---------------------\n";
    try {
        int topElement;
        ls.peek(topElement);
        cout << "Peeked Value: " << topElement << endl;
    } catch (const Exception& e) {
        cout << e.name << endl;
    }
    try{
        ls.pop(data);
        cout << "Popped Value: " << data << endl;
    }catch (const Exception& e){
        cout <<e.name<< endl;
    }
    ls.display();
    return 0;
}
