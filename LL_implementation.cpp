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
  tail = temp; // or tail = tail->next;
}
// function to add a node at any position

void insertAtPosition(Node* &head, Node* &tail,int position, int d){
  //insert a start 
  if (position == 1 ){
    insertAtHead(head,d);
    return;
  }
  // temp node is pointing to head ;
  Node* temp = head;
  int cnt = 1;
  while(cnt < position-1){
    temp = temp->next;
    cnt++;
  }
  //adding a node at the end;
  if(temp->next == NULL){
    insertAtTail(tail,d);
    return;
  }
  //creating node for d
  Node* nodeToInsert = new Node(d);
  nodeToInsert -> next = temp->next;
  temp -> next = nodeToInsert;


}

int main(){
  //created a new node;
  Node* node1 = new Node(10);
  // cout<< node1 -> data << endl;
  // cout<< node1 -> next << endl;

  // head pointd to node1;
  Node* head = node1;
  Node* tail = node1;
  print(head);

  insertAtHead(head,12);
  print (head);
  insertAtHead(head,15);
  print (head);

  insertAtTail(tail,25);
  print(head);
  insertAtPosition(head,3,14);
  print(head);
  insertAtPosition(head,1,20);
  print(head);
  insertAtPosition(head,6,50);
  print(head);

  return 0;
}
