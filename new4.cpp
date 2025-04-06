#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	stack<char>st;
	string str;
	getline(cin, str);
	int size = str.length();
	int count = 0;
	
	for(int i=0; i < size ;i++){
		if(str[i] == '<' && str[i+1] == '<'){
			st.push('<');
			i++;
		} else if(str[i] == '>' && str[i+2] == '>'){
			st.pop();
			count++;
			i++;
		} else if(str[i] == '(' || str[i] == '[' || str[i] == '{' || str[i] == '<'){
			st.push(str[i]);
		} else if(str[i] == ')' || str[i] == ']' || str[i] == '}' || str[i] == '>'){
			if(str[i] == ')' && st.top() == '(' ||
			   str[i] == '[' && st.top() == ']' ||
			   str[i] == '{' && st.top() == '}' ||
			   str[i] == '<' && st.top() == '>' ){
			   	st.pop();
			   	count++;
			   } else {
			   		break;
			   }
		}
	}
	if(!st.empty()){
		cout << "Not matched" << endl;
	}
	cout << count << " matched" << endl;
}
//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//
//int main(){
//	stack<char>st;
//	string input;
//	getline(cin, input);
//	int size = input.length();
//	int count = 0;
//	bool matched = true;
//	for(int i=0; i<size; i++){
//		char ch = input[i];
//		if(ch == '(' || ch == '[' || ch == '{' || ch == '<'){
//			st.push(ch);
//		} else if(ch == '<' && i+1 < size && input[i+1] == '<'){
//			st.push(ch);
//			i++;
//		} else if(ch == ')' || ch == ']' || ch == '}' || ch == '>' || (ch == '>' && i+1 < size && input[i+1] == '>')){
//			if(st.empty()){
//				matched = false;
//				break;
//			}
//			char top = st.top();
//			st.pop();
//			if((ch == ')' && top != '(') ||
//			   (ch == ']' && top != '[') ||
//			   (ch == '}' && top != '{') ||
//			   (ch == '>' && top != '<') ||
//			   (ch == '>' && (i+1 < size && input[i+1] == '>') && top != '<')){
//			   	matched = false;
//			   	break;
//			   }
//			   count++;
//			   if(ch == '>' && i+1 < size && input[i+1] == '>'){
//			   	i++;
//			   }
//		}
//	}
//	if(matched && st.empty()){
//		cout << count << " matched" << endl;
//	} else {
//		cout << "Not matched" << endl;
//		cout << count << " matched" << endl;
//	}
//	return 0;
//}