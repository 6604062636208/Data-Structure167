#include<iostream>
using namespace std;

class Queue{
    public:
    int arr[20];
    int rear = -1;
    int front = 0;
    int temp = 0;
    int empty(){
        return temp == 0;
    }
    int full(){
        return temp == 20;
    }
    void enqueue(int x){
        if(!full()){
            rear++;
            arr[rear]=x;
            ++temp;
        }
    }
    int dequeue(){
    if(!empty()){
        int value = arr[front];
        front++;
        --temp;
        return value;
    }
        return -1;
    }
    int gettemp(){
        return temp;
    }
    void printQueue() {
        if (!empty()) {
            int i = front;
            int elementsPrinted = 0;
            while (elementsPrinted < temp) {
                cout << arr[i] << " ";
                i = (i + 1) ; 
                ++elementsPrinted;
            }
            cout << endl;
        } else {
            cout << "Queue is empty" << endl;
        }
    }
    void showFrontAndBack() {
        if (!empty()) {
            int back = rear;
            cout << arr[front] << " " << arr[back] << endl;
        } else {
            cout << "Queue is empty" << endl;
        }
    }
};
int main(){
    Queue q;
    char ch;
    int n;
    while (true) {
        cin >> ch;
        if (ch == 'x') {
            break;
        }
        switch (ch) {
            case 'e':
                cin >> n;
                q.enqueue(n);
                break;
            case 'd':
                cout << q.dequeue() << endl;
                break;
            case 'p':
                q.printQueue();
                break;
            case 'n':
                cout << q.gettemp() << endl;
                break;
            case 's':
                q.showFrontAndBack();
                break;
            default:
                cout << "Invalid command" << endl;
                break;
        }
    }
    return 0;
}
