#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to reverse a linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

// Function to check if linked list is palindrome
bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true;

    // Step 1: Find the middle of the linked list
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    ListNode* secondHalf = reverseList(slow);

    // Step 3: Compare the first half and the reversed second half
    ListNode* firstHalf = head;
    ListNode* secondHalfCopy = secondHalf; // To restore the list later

    bool palindrome = true;
    while (secondHalf != nullptr) {
        if (firstHalf->val != secondHalf->val) {
            palindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Step 4: Restore the second half (optional)
    reverseList(secondHalfCopy);

    return palindrome;
}

// Helper function to insert a new node at the end of the list
void insert(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Helper function to print the list (for debugging)
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ListNode* head = nullptr;

    // Example: Linked list: 1 -> 2 -> 2 -> 1
    insert(head, 1);
    insert(head, 2);
    insert(head, 2);
    insert(head, 1);

    cout << "Original List: ";
    printList(head);

    if (isPalindrome(head)) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The list is not a palindrome." << endl;
    }

    cout << "Restored List: ";
    printList(head);

    return 0;
}
