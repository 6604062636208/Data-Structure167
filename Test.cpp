#include <iostream>
#include <stack>
using namespace std;

class Stack{
    public:
    int Array[5];
    int top = 0;
    Stack() { Array[0] = 10; }
    bool empty(){
        if(top == 0){
            return true;
        } else {
            return false;
        }
    }
    bool full(){
        if(top == Array[0]){
            return true;
        } else {
            return false;
        }
    }
    void push(int data){
        if(!full()){
            top++;
            Array[top] = data;
        }
    }
    int pop(){
        if(!empty()){
            int temp = Array[top];
            top--;
            return temp;
        }
        return -1;
    }
    void print(){
        cout << "Stack : ";
        for(int i=1; i<=top; i++){
            cout << Array[i] << " ";
        }
        cout<<endl;
    }
};
int main(){
    Stack s;
    s.push(1); 
    s.print();
    s.push(2); 
    s.print();
    s.push(3); 
    s.print();
    s.push(4); 
    s.print();
    s.push(5); 
    s.print();
    s.push(6);
    s.print();
    s.push(7); 
    s.print();
    s.push(8); 
    s.print();
    s.push(9);
    s.print();
    s.push(10);
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    return 0;  
}