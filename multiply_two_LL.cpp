#include <iostream>
using namespace std;

#define MOD 1000000007

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Function to convert linked list to a number
long long listToNumber(Node* head) {
    long long num = 0;
    while (head != NULL) {
        num = (num * 10 + head->data) % MOD; // Accumulate the number mod MOD
        head = head->next;
    }
    return num;
}

// Function to multiply two linked lists
long long multiplyTwoLists(Node* l1, Node* l2) {
    // Convert both linked lists to numbers
    long long num1 = listToNumber(l1);
    long long num2 = listToNumber(l2);
    
    // Multiply the numbers and take modulo MOD
    return (num1 * num2) % MOD;
}

// Helper function to print the linked list (for debugging or checking)
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Example usage
int main() {
    // Create first linked list: 1 -> 2 -> 3 (represents number 123)
    Node* l1 = new Node(1);
    l1->next = new Node(2);
    l1->next->next = new Node(3);
    
    // Create second linked list: 4 -> 5 -> 6 (represents number 456)
    Node* l2 = new Node(4);
    l2->next = new Node(5);
    l2->next->next = new Node(6);
    
    // Multiply the two linked lists
    cout << "Result: " << multiplyTwoLists(l1, l2) << endl;  // Output will be 123 * 456 % (10^9 + 7)

    return 0;
}
