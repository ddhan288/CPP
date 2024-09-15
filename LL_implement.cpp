// #include<iostream>
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Node {
  public:
  int data;
  Node* next;

  //constructor
  Node(int data){
    this -> data = data;
    this -> next = NULL;
  }
  ~Node(){
    int value = this ->data;
    if(this->next !=NULL){
      delete next;
      this->next =NULL;
    }
    cout<<"node deleted"<< value<<endl;
  }
};

void insertAtHead(Node* &head, int d ){
  //new node create
  Node* temp = new Node(d);
  temp->next = head;
  head = temp;
}
void insertAtTail(Node* &tail, int d){
  Node*temp = new Node(d);
  tail -> next = temp;
  tail = temp;


}
void insertAtPos(Node* &head,Node* &tail,int d, int pos){
  if (pos == 1){
    insertAtHead(head,d);
    return ;
  }
  //traversing
  Node* temp = head;
  int cnt = 1;

  while(cnt < pos-1){
    temp= temp->next ;
    cnt++;
  }
  //inserting at last position
  if(temp->next == NULL ){
    insertAtTail(tail,d);
    return;
  }
  //creatin a node for d
  Node* nodeToInsert = new Node(d);
  nodeToInsert->next = temp->next;
  temp->next = nodeToInsert;
}
void deleteNode(int pos, Node* head){
  if (pos ==1){
    Node* temp = head;
    head = head->next;
    // memory free
    temp->next = NULL;
    delete temp;
  }
else{
    // deleting any middle or last node
    Node* curr = head;
    Node* prev = NULL;

    int cnt =1;
    while (cnt < pos){
      prev= curr;
      curr = curr->next;
      cnt ++;
    }
    prev->next = curr->next;
    curr-> next = NULL;
    delete curr;
  }
}
void print(Node* &head){
  Node* temp =head;
  while(temp!= NULL){
    cout <<temp->data << " ";
    temp = temp-> next;
  }
  cout <<endl;
}
int main() {
  Node* node1= new Node(10);
  // cout<<node1 -> data<<endl;
  // cout<<node1 -> next<<endl;

  //head pointed to node1
  Node* head = node1;
  Node* tail = node1;
  print(head);
  insertAtHead(head,12);
  print(head);
  insertAtHead(head,15);
  print(head);
  insertAtTail(tail,22);
  print(head);
  
  insertAtPos(head,tail,25,1);
  print(head);
  cout<< "head "<< head-> data<<endl;
  cout << "tail "<< tail-> data<<endl;

  deleteNode(4,head);
  print(head);
  cout<< "head "<< head-> data<<endl;
  cout << "tail "<< tail-> data<<endl;
  
  deleteNode(3,head);
  print(head);
  cout<< "head "<< head-> data<<endl;
  cout << "tail "<< tail-> data<<endl;
  deleteNode(2,head);
  print(head);
  cout<< "head "<< head-> data<<endl;
  cout << "tail "<< tail-> data<<endl;
  deleteNode(1,head);
  print(head);
  cout<< "head "<< head-> data<<endl;
  cout << "tail "<< tail-> data<<endl;

  return 0;
}
