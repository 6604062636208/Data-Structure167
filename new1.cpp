#include <iostream>
using namespace std;

class Stack {
    public:
		int top = -1;
		int arr[100];
		
		bool empty(){
			if(top == -1) {
				return true;
			} else {
				return false;
			}
		}
		bool full(){
			if(top == 100-1){
				return true;
			} else {
				return false;
			}
		}
		void push(int data) {
			if(!full()){
				top++;
				arr[top] = data;
			}
		}
		int pop(){
			if(!empty()){
				int temp = arr[top];
				top--;
				return temp;
			}
			return -1;
		}
		void print(){
			for(int i = 0; i <= top; i++){
				cout << arr[i] << " ";
			}
			cout << endl;
		}
		int count(){
			int count = 0;
			for(int j=0 ;j<top; j++){
				count++;
			}
			return count;
		}
};
int main(){
	Stack s;
	char ch;
	int n = 0;
	while(ch != 'X'){
		cin >> ch;
		if(ch == 'U'){
			cin >> n;
			s.push(n);
		} if(ch == 'O'){
			int O = s.pop();
			cout << O << endl;
		} if(ch == 'T'){
			cout << s.arr[s.top] << endl;
		} if(ch == 'P'){
			s.print();
		} if(ch == 'N'){
//			int co = s.count();
//			cout<<co+1<<endl;
			cout << s.count() << endl;
		} if(ch == 'X') {
			break;
		}
	}
	return 0;
}