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
    Node *next;
    Node(int _data){
        data = _data;
        next = nullptr;
    }
};
class QueueCircular{
    int data;
    Node *front;
    Node *rear;
public:
    QueueCircular()
    {
        front= nullptr;
        rear = nullptr;
    }
    bool IsEmpty()
    {
        return (front==nullptr);
    }
    void enQueue(int data)
    {
        Node *newNode=new Node(data);
        if(IsEmpty())
        {
            front = rear = newNode;
            rear->next=front;
        }
        else
        {
            rear->next = newNode; // Add New Node After Rear
            rear=newNode; // let Rear be the new Node
            rear->next = front;// let the next to rear is front in case of circular
        }
    }
    void deQueue(int &data)
    {
        if(IsEmpty())
        {
            throw Exception(102, "Queue is Empty");
        }
        else
        {
            data = front->data;
            Node* temp = front;
            if(front==rear)
            {
                front =rear= nullptr;
            } else
            {
                front= front->next;
                rear->next=front;
            }
            delete temp;
        }
    }
    int Getfront()
    {
        if (IsEmpty()) {
            throw Exception(102, "Queue is Empty");
        }
        return front->data;
    }
    int Getrear()
    {
        if (IsEmpty()) {
            throw Exception(102, "Queue is Empty");
        }
        return rear->data;
    }
    void display()
    {
        if (IsEmpty()) {
            cout << "Queue is Empty" << endl;
            return;
        }
        Node* temp = front;
        do {
            cout << temp->data << "\t";
            temp = temp->next;
        } while (temp != front);  // Stop when we come back to the front
        cout << endl;
    }
};
int main() {
    QueueCircular q;
    try {
        q.enQueue(10);
        q.enQueue(20);
        q.enQueue(30);
        q.enQueue(40);
        q.enQueue(50);

        q.display();  // Displays: 10 20 30 40 50
    } catch (const Exception& e) {
        cout << "Error [" << e.code << "]: " << e.name << endl;
    }

    try {
        cout << "GetFront: " << q.Getfront() << endl;  // Should print 10
        cout << "GetRear: " << q.Getrear() << endl;    // Should print 50
    } catch (const Exception& e) {
        cout << "Error [" << e.code << "]: " << e.name << endl;
    }

    try {
        int data;
        q.deQueue(data);
        cout << "Dequeued: " << data << endl;
        q.display();
    } catch (const Exception& e) {
        cout << "Error [" << e.code << "]: " << e.name << endl;
    }

    try {
        cout << "GetFront: " << q.Getfront() << endl;
        cout << "GetRear: " << q.Getrear() << endl;
    } catch (const Exception& e) {
        cout << "Error [" << e.code << "]: " << e.name << endl;
    }

    try {
        q.enQueue(60);
        q.enQueue(70);
        q.display();
    } catch (const Exception& e) {
        cout << "Error [" << e.code << "]: " << e.name << endl;
    }

    return 0;
}
