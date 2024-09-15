#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Node {
  public:
    int data;
    Node* next;

  //constructor 
  Node(int data) {
        this-> data = data;
        this-> next = NULL;
    }
};

void print(Node* &head){
  //create a new node 
  Node* temp = head;
  while(temp!= NULL){
    cout<< temp->data<< " ";
    temp = temp->next;
  }
  cout << endl;
}

//function to add a node at the front(head)
void insertAtHead (Node* &head, int d){
  // create a node;
  Node* temp = new Node(d);
  temp->next = head;
  head = temp;
}
// function to add a node at the end (tail)
void insertAtTail(Node* &tail, int d){
  //create a node 
  Node* temp = new Node(d);
  tail->next = temp;
  tail = temp;
}

int main(){
  //created a new node;
  Node* node1 = new Node(10);
  // cout<< node1 -> data << endl;
  // cout<< node1 -> next << endl;

  // head pointd to node1;
  Node* head = node1;
  print(head);

  insertAtHead(head,12);
  print (head);
  insertAtHead(head,15);
  print (head);

  return 0;
}
