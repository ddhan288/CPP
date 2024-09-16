#include<bits/stdc++.h>
#include<iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}  // Constructor for convenience
};
struct ListNode * intersectingNode(struct ListNode * head1,struct ListNode* head2){
  struct ListNode * temp;
  while(head1 != NULL){
    temp = head2;
    while(temp!=NULL){
      if (temp == head1){
        return head1;
      }
      temp = temp->next;
    }
    head1 = head1 ->next;
  }
  return NULL;
}
int main() {
    // Example usage

    // Creating two intersecting linked lists
    ListNode* common = new ListNode(45);  // This is the intersection node
    common->next = new ListNode(10);

    // List 1: 3 -> 6 -> 9 -> 8 -> 10
    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(6);
    head1->next->next = new ListNode(9);
    head1->next->next->next = common;

    // List 2: 4 -> 8 -> 10 (intersects at 8)
    ListNode* head2 = new ListNode(4);
    head2->next = common;

    // Find intersection
    ListNode* result = intersectingNode(head1, head2);
    
    if (result != NULL) {
        cout << "Intersecting Node: " << result->val << endl;
    } else {
        cout << "No intersection." << endl;
    }

    return 0;
}