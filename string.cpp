#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> s;
    string str;
    getline(cin, str);
    int size = str.length();
    int count = 0;
    bool matched = true;
    for (int i = 0; i < size; i++) {
        char ch = str[i];
        if (ch == '(' || ch == '[' || ch == '{' || ch == '<') {
            s.push(ch);
        } 
        else if (ch == '<' && i + 1 < size && str[i + 1] == '<') {
            s.push(ch);
            i++;
        } 
        else if (ch == ')' || ch == ']' || ch == '}' || ch == '>' || (ch == '>' && i + 1 < size && str[i + 1] == '>')) {
            if (s.empty()) {
                matched = false;
                break;
            }
            char top = s.top();
            s.pop();
            if ((ch == ')' && top != '(') || 
                (ch == ']' && top != '[') || 
                (ch == '}' && top != '{') || 
                (ch == '>' && top != '<') || 
                (ch == '>' && (i + 1 < size && str[i + 1] == '>') && top != '<')) {
                matched = false;
                break;
            }
            count++;
            if (ch == '>' && i + 1 < size && str[i + 1] == '>') {
                i++;  
            }
        }
    }
    if (matched && s.empty()) {
        cout << count << " matched" << endl;
    } 
	else {
        cout << "Not matched" << endl;
        cout << count << " matched" << endl;
    }
    return 0;
}
//(((20+5)+61
//(20+[30 - 40<int> + 50]-a[40]{})
//>20(30{40[20]})<
//<<a+<int>b+c[40-{50+60(20)}]-<int>+b>>
//a+b-<<c+d<< -f ({d[30]})>>