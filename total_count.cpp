#include <iostream>
#include <vector>
using namespace std;

int countMinimumParts(vector<int>& arr, int k) {
    int totalParts = 0;
    
    // Loop through each element in the array
    for (int num : arr) {
        // Calculate the number of parts for each element
        int parts = (num + k - 1) / k;
        totalParts += parts;
    }
    
    return totalParts;
}

int main() {
    // Example Usage
    vector<int> arr = {5, 8, 10, 13};
    int k = 3;
    
    int result = countMinimumParts(arr, k);
    cout << "Total number of parts: " << result << endl;
    
    return 0;
}
