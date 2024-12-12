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
class Stack
{
    int size;
    int *items;
    int top;
public:
    Stack(int size=5)
    {
        this->size = size;
        top =-1;
        items= new int[size];
    }
    void push (int data)
    {
        if(top==size-1)
        {
            throw Exception (102,"Stack is Full");
        }
        //cout << "Stack is Full\n";
        items[++top]=data;
    }
    void pop(int &data)
    {
        if(top>-1)
        {
            data = items[top--];
        }
        else
        {
            throw Exception (101,"Stack Is Empty");
        }
    }
    void peek(int &data)
    {
        if(top>-1)
        {
            data = items[top];
        }
        else
        {
            throw Exception (101,"Stack Is Empty");
        }
    }
    void display()
    {
        if(top==-1)
        {
            cout << "Stack Is Empty.\n";
            return;
        }
        for(int i=top;i>=0;--i)
        {
            cout <<items[i] <<"\t";
        }
        cout <<endl;
    }
    ~Stack()
    {
        delete[] items;
    }
};
int main() {
    Stack s;
    int data;

    try {
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);

        s.display();

        s.push(60); // This will throw an exception
    } catch (const Exception& e) {
        cout << "Error [" << e.code << "]: " << e.name << endl;
    }

    try {
        cout << "Peeked Value: ";
        s.peek(data);
        cout << data << endl;
    } catch (const Exception& e) {
        cout << "Error [" << e.code << "]: " << e.name << endl;
    }

    try {
        while (true) {
            s.pop(data);
            cout << "Popped Value: " << data << endl;
        }
    } catch (const Exception& e) {
        cout << "Error [" << e.code << "]: " << e.name << endl;
    }
    try{
        s.pop(data);
        cout << "Popped Value: " << data << endl;
    }catch (const Exception& e){
        cout <<e.name<< endl;
    }
    cout << "Final Stack State:" << endl;
    s.display();
    return 0;
}
