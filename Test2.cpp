#include <iostream>
using namespace std;
class Queue {
    public:
    int arr[11];
    int size = 10;
    int front = 0;
    int rear = 0;
    bool empty(){
        if(front == 0 && rear == 0){
            return 1;
        }
        else {
            return 0;
        }
    }
    bool full(){
        if((front == 1)&&(rear == size)||(front == rear+10)&&(rear < size)){
            return 1;
        }
        else {
            return 0;
        }
    }
    void enqueue(int data){
         if(!full()){
            if(empty()){
                front = 1;
                rear = 1;
            }
            else {
                if(rear == size){
                    rear = 1;
                }
                else {
                    rear++;
                }
            }
            arr[rear] = data;
        }
    }
    int dequeue(){
       if(!empty()){
        int temp = arr[front];
        if(front == rear){
            rear = 0;
            front = 0;
        }
        else if(front == size){
            front = 1;
        }
        else {
            front++;
        }
        return temp;
       }
        return -1;
    }
    void print(){
        cout << "Queue ";
        if(front > 0 && rear > 0){
            if(front <= rear){
                for(int i=front; i<=rear; i++){
                    cout << arr[i] << " "; 
                }
            }
            else{
                for(int i=front; i<=size; i++){
                    cout << arr[i] << " ";
                }
                for(int i=1; i<=rear; i++) {
                    cout << arr[i] << " ";
                }
            }
        }
        cout << endl;
    }
};
int main(){
    Queue q;
    q.enqueue(1); cout<<"Enqueue1\t";
    q.print();
    q.enqueue(2); cout<<"Enqueue2\t";
    q.print();
    cout<<"Dequeue\t"; cout<<q.dequeue()<<"\t";
    q.print();
    q.enqueue(3); cout<<"Enqueue3\t";
    q.print();
    q.enqueue(4); cout<<"Enqueue4\t";
    q.print();
    q.enqueue(5); cout<<"Enqueue5\t";
    q.print();
    cout<<"Dequeue\t"; cout<<q.dequeue()<<"\t";
    q.print();
    q.enqueue(6); cout<<"Enqueue6\t";
    q.print();
    q.enqueue(7); cout<<"Enqueue7\t";
    q.print();
    cout<<"Dequeue\t"; cout<<q.dequeue()<<"\t";
    q.print();
    q.enqueue(8); cout<<"Enqueue8\t";
    q.print();
    cout<<"Dequeue\t"; cout<<q.dequeue()<<"\t";
    q.print();
    q.enqueue(9); cout<<"Enqueue9\t";
    q.print();
    q.enqueue(10); cout<<"Enqueue10\t";
    q.print();
    cout<<"Dequeue\t"; cout<<q.dequeue()<<"\t";
    q.print();
    cout<<"Dequeue\t"; cout<<q.dequeue()<<"\t";
    q.print();
    cout<<"Dequeue\t"; cout<<q.dequeue()<<"\t";
    q.print();
    cout<<"Dequeue\t"; cout<<q.dequeue()<<"\t";
    q.print();
    cout<<"Dequeue\t"; cout<<q.dequeue()<<"\t";
    q.print();
    cout<<"Dequeue\t"; cout<<q.dequeue()<<"\t";
    q.print();
    return 0;
}