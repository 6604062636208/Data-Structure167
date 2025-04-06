#include <iostream>
using namespace std;

class Queue{
	public:
	int arr[10];
	int front = 1;
	int rear = 0;
	int size = 8;

	bool empty(){
		if(front > rear){
			return 1;
		} else {
			return 0;
		}
	}
	bool full(){
		if(rear == size){
			return 1;
		} else {
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
		for(int i=front; i<=rear; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	int count(){
		int count = 0;
		for(int i=front; i<=rear; i++){
			count++;
		}
		return count;
	}
	void showfrontandback(){
		if(!empty()){
			cout << arr[front] << " " << arr[rear] << endl;
		}
		else {
			cout << "Queue is Empty!" << endl;
		}
	}
};

int main(){
	Queue q;
	char ch;
	int value = 0;

	while(ch != 'x'){
		cin >> ch;
		if(ch == 'e'){
			cin >> value;
			q.enqueue(value);
		}
		if(ch == 'd'){
			cout << q.dequeue() << endl;
		}
		if(ch == 'p'){
			q.print();
		}
		if(ch == 'n'){
			cout << q.count() << endl;
		}
		if(ch == 's'){
			q.showfrontandback();
		}
	}
	return 0;
}