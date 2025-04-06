#include <iostream>
#include <stack>
using namespace std;

int main(){
	stack<char>s;
	string input;
	getline(cin, input);

	for(int i=0; i<input.length(); i++){
		char c = input[i];
		if(c == '('){
			s.push(input[i]);
		}else if(c == ')'){
			if(s.empty()){
				cout << "Error" << endl;
				return 0;
			}else {
				s.pop();
			}
		}
	}
	if(s.size() == 0){
		cout << "Pass" << endl;
	} else {
		cout << "Error" << endl;
	}
}

