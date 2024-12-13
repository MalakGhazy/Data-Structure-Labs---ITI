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
        front=rear=-1;
    }
    bool IsFull()
    {
        return (rear + 1) % size == front;
        //return ((rear==size && front==0) || front == rear+1);//size-1
        //rear==size // front=0
    }
    bool IsEmpty()
    {
        return (rear==-1 && front ==-1);
    }
    void enQueue(int data)
    {
        if(IsFull())
        {
            throw Exception(101,"Queue is Full");
        }
        else if (IsEmpty())
        {
            rear = front=0;
            items[front]=data;
        }
        else{
            rear=(rear+1)%size;
            items[rear]=data;
        }
    }
    void deQueue(int &data)
    {
        if(IsEmpty())
        {
            throw Exception(102,"Queue is Empty.");
        }
        data = items[front];
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front=(front+1)%size;
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
        return items[rear];
    }
    void display()
    {
        if(IsEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }
        int i = front;
        while (true)
        {
            cout<<items[i] <<"\t";
            if(i==rear)
                break;
            i=(i+1)%size;
        }
        cout <<endl;
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
        q.enQueue(80);
        q.enQueue(90);

        q.display(); // Displays: 10 20 30 40 50
    } catch (const Exception& e) {
        cout << "Error [" << e.code << "]: " << e.name << endl;
    }

    try {
        int data;
        q.deQueue(data);
        q.display(); // Displays: 20 30 40 50

        q.deQueue(data);
        q.display();

        q.deQueue(data);
        q.display();

        q.deQueue(data);
        q.display();

        q.deQueue(data);
        q.display();
    }catch (const Exception& e)
    {
        cout << "Error [" << e.code << "]: " << e.name << endl;
    }
    try {
        q.enQueue(80);
        q.enQueue(90);

        q.display(); // Displays: 10 20 30 40 50
    } catch (const Exception& e) {
        cout << "Error [" << e.code << "]: " << e.name << endl;
    }

    return 0;
}
