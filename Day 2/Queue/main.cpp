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
class Queue{
    int front;
    int rear;
    int size;
    int *items;
public:
    Queue(int size=5){
        this->size=size;
        items=new int [size];
        front=rear=0;
    }
    bool IsFull()
    {
        //        return (rear + 1) % size == front;
        return ((rear==size && front==0) || front == rear+1);//size-1
        //rear==size // front=0
    }
    bool IsEmpty()
    {
        return (rear==front);
    }
    void enQueue(int data)
    {
        if(IsFull())
        {
            throw Exception(101,"Queue is Full");
        } else{
            items[rear++]=data;
        }
    }
    void deQueue(int &data)
    {
        if(IsEmpty())
        {
            throw Exception(102,"Queue is Empty");
        }
        else
        {
            data = items[front++];
        }
    }
    int Getfront()
    {
        if (IsEmpty()) {
            throw Exception(102, "Queue is Empty");
        }
        return items[front];
    }
    int Getrear()
    {
        if (IsEmpty()) {
            throw Exception(102, "Queue is Empty");
        }
        return items[rear-1];
    }
    void display()
    {
        if(IsEmpty())
        {
            cout << "Queue is Empty";
            return;
        }
        else{
            for(int i=front;i<rear;i++)
            {
                cout << items[i] <<"\t";
            }
            cout <<endl;
        }
    }
    ~Queue()
    {
        delete[] items;
    }

};
int main() {
    Queue q;
    try {
        q.enQueue(10);
        q.enQueue(20);
        q.enQueue(30);
        q.enQueue(40);
        q.enQueue(50);

        q.display(); // Displays: 10 20 30 40 50
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
        int data;
        q.deQueue(data);
        q.display(); // Displays: 20 30 40 50
    }catch (const Exception& e)
    {
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

        q.display(); // Displays: 10 20 30 40 50
    } catch (const Exception& e) {
        cout << "Error [" << e.code << "]: " << e.name << endl;
    }
    return 0;
}