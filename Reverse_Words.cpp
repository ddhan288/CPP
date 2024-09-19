#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

namespace StringManipulation {
    string reverseWords(const string& str) {
        vector<string> words;
        string word;
        stringstream ss(str);

        // Split the string into words based on '.'
        while (getline(ss, word, '.')) {
            words.push_back(word);
        }

        // Reverse the order of words
        string result;
        for (int i = words.size() - 1; i >= 0; --i) {
            result += words[i];
            if (i != 0) {
                result += '.';
            }
        }

        return result;
    }
}

int main() {
    string str = "i.like.this.program.very.much";
    
    // Using the StringManipulation namespace to call the function
    string reversedStr = StringManipulation::reverseWords(str);
    cout << reversedStr << endl;  // Output: much.very.program.this.like.i

    return 0;
}
