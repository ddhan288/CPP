#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // Function to perform right rotation by one
    void rightRotate(vector<int>& arr) {
        int last = arr.back();  // Store the last element
        arr.pop_back();         // Remove the last element
        arr.insert(arr.begin(), last);  // Insert it at the beginning
    }

    // Function to implement the rotate-delete process
    int rotateDelete(vector<int>& arr) {
        int sz = arr.size();  // Initial size of the array
        
        // Perform the operations sz/2 times
        for (int k = 1; k <= sz / 2; ++k) {
            rightRotate(arr);  // Rotate the array
            int deleteIdx = arr.size() - k;  // Find the index to delete
            arr.erase(arr.begin() + deleteIdx);  // Delete the element
        }
        
        // Return the first element after all operations
        return arr[0];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5, 6};  // Example input
    cout << sol.rotateDelete(arr) << endl;  // Output the result
    return 0;
}
