#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the length of the longest proper prefix which is also a proper suffix
int longestPrefixSuffix(const string& s) {
    int n = s.length();
    
    // Create a vector to store the length of the longest proper prefix which is also suffix
    vector<int> lps(n, 0);
    
    int len = 0; // length of the previous longest prefix suffix
    int i = 1;
    
    // Build the LPS array
    while (i < n) {
        if (s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // Try to shorten the current "len"
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    // Return the longest proper prefix which is also suffix
    return lps[n - 1];
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    
    int result = longestPrefixSuffix(s);
    cout << "Length of the longest proper prefix which is also a proper suffix: " << result << endl;
    
    return 0;
}
