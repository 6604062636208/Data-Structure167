#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string expr;
    getline(cin, expr);
    stack<char> s;
    int matched_pairs = 0;
    int unmatched = 0;

    for(int i=0;i<expr.length();i++) {
    	char ch = expr[i];
        if (ch == '(' || ch == '[' || ch == '{' || ch == '<') {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}' || ch == '>') {
            if (s.empty()) {
                unmatched++;
            } else {
                char top = s.top();
                s.pop();
                if ((ch == ')' && top == '(') ||
                    (ch == ']' && top == '[') ||
                    (ch == '}' && top == '{') ||
					(ch == '<' && top == '>')){
                    matched_pairs++;
                } else {
                    unmatched++; 
                }
            }
        }
    }
    unmatched += s.size();
    cout << matched_pairs << " matched pairs" << endl;
    cout << unmatched << " unmatched" << endl;
    return 0;
}
//(((20+5)+61
//(20+[30 - 40<int> + 50]- a[40]{})
//>20(30{40[20]})<
//<<a+<int>b+c[40-{50+60(20)}]-<int>+b>>
//a+b-<<c+d<< -f ({d[30]})>>