#include <iostream>
#include <stack>
using namespace std;

bool areBracketsBalanced(string x) {
    stack<char> s;
    
    // Traverse the given expression using traditional for loop
    for (int i = 0; i < x.length(); i++) {
        char ch = x[i];
        
        // If it's an opening bracket, push it to the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } 
        // If it's a closing bracket, check if the stack is empty or doesn't match the top of the stack
        else {
            if (s.empty()) {
                return false;  // Stack empty means there's no matching opening bracket
            }
            char top = s.top();
            s.pop();
            
            // Check if the popped element matches the current closing bracket
            if ((ch == ')' && top != '(') || 
                (ch == '}' && top != '{') || 
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }
    
    // In the end, if the stack is not empty, there are unmatched opening brackets
    return s.empty();
}

int main() {
    string exp = "{([])}";
    
    if (areBracketsBalanced(exp)) {
        cout << "balanced" << endl;
    } else {
        cout << "not balanced" << endl;
    }
    
    return 0;
}
