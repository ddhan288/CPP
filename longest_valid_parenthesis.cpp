#include <iostream>
#include <string>
#include <algorithm>  // for std::max

using namespace std;

int longestValidParentheses(string s) {
    int left = 0, right = 0;
    int max_len = 0;

    // Left to Right pass
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }

        if (left == right) {
            max_len = max(max_len, 2 * right);
        } else if (right > left) {
            left = right = 0;  // Reset counters if right exceeds left
        }
    }

    // Reset counters for Right to Left pass
    left = right = 0;

    // Right to Left pass
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == ')') {  // Corrected: Check for closing parenthesis first
            right++;
        } else {
            left++;
        }

        if (left == right) {
            max_len = max(max_len, 2 * left);
        } else if (left > right) {
            left = right = 0;  // Reset counters if left exceeds right (corrected for this pass)
        }
    }

    return max_len;
}

int main() {
    string s = "(()))())(";   // Example input
    cout << "The longest valid parentheses length is: " << longestValidParentheses(s) << endl;
    return 0;
}
