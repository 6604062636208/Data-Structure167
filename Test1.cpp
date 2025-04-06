#include <iostream>
using namespace std;
class Queue {
    public:
    int arr[11];
    int size = 10;
    int front = 1;
    int rear = 0;
    bool empty(){
        if(front > rear){
            return 1;
        }
        else {
            return 0;
        }
    }
    bool full(){
        if(rear == size){
            return 1;
        }
        else {
            return 0;
        }
    }
    void enqueue(int data){
        if(!full()){
            rear++;
            arr[rear] = data; 
        }
    }
    int dequeue(){
        if(!empty()){
            int temp = arr[front];
            front++;
            return temp;
        }
        return -1;
    }
    void print(){
        cout << "Queue ";
        for(int i=front; i<=rear; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
};
int main(){
    Queue q;
    q.enqueue(1); cout << "Enqueue 1\t";
    q.print();
    q.enqueue(2); cout << "Enqueue 2\t";
    q.print();
    q.enqueue(3); cout << "Enqueue 3\t";
    q.print();
    q.enqueue(4); cout << "Enqueue 4\t";
    q.print();
    q.enqueue(5); cout << "Enqueue 5\t";
    q.print();
    q.enqueue(6); cout << "Enqueue 6\t";
    q.print();
    q.enqueue(7); cout << "Enqueue 7\t";
    q.print();
    q.enqueue(8); cout << "Enqueue 8\t";
    q.print();
    q.enqueue(9); cout << "Enqueue 9\t";
    q.print();
    q.enqueue(10); cout << "Enqueue 10\t";
    q.print();
    cout << "Dequeue\t"; cout << q.dequeue() << "\t";
    q.print();
    cout << "Dequeue\t"; cout << q.dequeue() << "\t";
    q.print();
    cout << "Dequeue\t"; cout << q.dequeue() << "\t";
    q.print();
    cout << "Dequeue\t"; cout << q.dequeue() << "\t";
    q.print();
    cout << "Dequeue\t"; cout << q.dequeue() << "\t";
    q.print();
    cout << "Dequeue\t"; cout << q.dequeue() << "\t";
    q.print();
    cout << "Dequeue\t"; cout << q.dequeue() << "\t";
    q.print();
    cout << "Dequeue\t"; cout << q.dequeue() << "\t";
    q.print();
    cout << "Dequeue\t"; cout << q.dequeue() << "\t";
    q.print();
    cout << "Dequeue\t"; cout << q.dequeue() << "\t";
    q.print();
    return 0;
}