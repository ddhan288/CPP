#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if (!head) return NULL;

    // Step 1: Create new nodes and interleave them with the original nodes
    Node* curr = head;
    while (curr) {
        Node* newNode = new Node(curr->val);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }

    // Step 2: Assign the random pointers for the new nodes
    curr = head;
    while (curr) {
        if (curr->random) {
            curr->next->random = curr->random->next;
        }
        curr = curr->next->next;
    }

    // Step 3: Restore the original list and extract the copied list
    curr = head;
    Node* copyHead = head->next;
    Node* copyCurr = copyHead;
    while (curr) {
        curr->next = curr->next->next;
        if (copyCurr->next) {
            copyCurr->next = copyCurr->next->next;
        }
        curr = curr->next;
        copyCurr = copyCurr->next;
    }

    return copyHead;
}

// Helper function to print the list for debugging
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Node value: " << temp->val;
        if (temp->random)
            cout << ", Random points to: " << temp->random->val;
        else
            cout << ", Random points to: NULL";
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Example usage:

    // Create a list with random pointers
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    
    // Setting random pointers
    head->random = head->next->next; // 1 -> 3
    head->next->random = head;       // 2 -> 1
    head->next->next->random = head->next; // 3 -> 2

    cout << "Original list:\n";
    printList(head);

    // Clone the list
    Node* clonedList = copyRandomList(head);

    cout << "\nCloned list:\n";
    printList(clonedList);

    return 0;
}
