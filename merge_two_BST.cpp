#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform in-order traversal of the tree and store result in a vector.
void inorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    inorderTraversal(root->left, result);
    result.push_back(root->val);
    inorderTraversal(root->right, result);
}

// Function to merge two sorted vectors into one sorted vector.
vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;
    
    // Merge both arrays
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }
    
    // If any elements remain in arr1
    while (i < arr1.size()) {
        merged.push_back(arr1[i]);
        i++;
    }
    
    // If any elements remain in arr2
    while (j < arr2.size()) {
        merged.push_back(arr2[j]);
        j++;
    }
    
    return merged;
}

// Function to merge two BSTs and return their elements in sorted form.
vector<int> mergeBSTs(TreeNode* root1, TreeNode* root2) {
    vector<int> bst1, bst2;
    
    // Get sorted elements of both trees via inorder traversal
    inorderTraversal(root1, bst1);
    inorderTraversal(root2, bst2);
    
    // Merge the two sorted arrays
    return mergeSortedArrays(bst1, bst2);
}

int main() {
    // Example usage:
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(5);
    
    TreeNode* root2 = new TreeNode(4);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(6);
    
    vector<int> result = mergeBSTs(root1, root2);
    
    // Output the result
    for (int val : result) {
        cout << val << " ";
    }
    
    return 0;
}
