#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char>s;
	string input;
	cin>>input;
	
	int i;
	for(i = 0; i<input.length();i++){
		char character = input[i];
		if(character=='('){
			s.push(input[i]);
			}else if(character==')') {
				if(s.empty()){
					cout<<"Error"<<endl;
					return 0;
				}else{
					s.pop();
				}
			}
		}
	if(s.size() == 0) {
		cout<<"Pass"<<endl;
	}
	else {
		cout<<"Error"<<endl;
	}
}

