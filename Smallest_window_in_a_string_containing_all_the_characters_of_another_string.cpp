#include <iostream>
#include <string>
#include <climits>
using namespace std;

string smallestWindow(string s, string p) {
    int lenS = s.size();
    int lenP = p.size();
    
    if (lenP > lenS) {
        return "-1";
    }

    int p_freq[256] = {0}, window_freq[256] = {0};

    for (char c : p) {
        p_freq[c]++;
    }

    int required = lenP;  
    int left = 0, right = 0, formed = 0;
    int min_len = INT_MAX, min_left = 0;

    while (right < lenS) {
        char c = s[right];
        window_freq[c]++;

        if (p_freq[c] > 0 && window_freq[c] <= p_freq[c]) {
            formed++;
        }

        while (left <= right && formed == required) {
            c = s[left];

            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                min_left = left;
            }

            window_freq[c]--;
            if (p_freq[c] > 0 && window_freq[c] < p_freq[c]) {
                formed--;
            }

            left++;
        }

        right++;
    }

    if (min_len == INT_MAX) {
        return "-1";
    }

    return s.substr(min_left, min_len);
}

int main() {
    string s = "timetopractice";
    string p = "toc";
    
    string result = smallestWindow(s, p);
    cout << "Smallest window: " << result << endl;
    
    return 0;
}
