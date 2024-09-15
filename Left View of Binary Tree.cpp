#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node {
  public:
    Node* left;
    Node* right;
    int data;

  Node(int data){
    this-> left = NULL ;
    this -> right = NULL;
    this -> data = data;
  }
};

void preorderTraversal(Node* root){
  //base case
  if(root == NULL){
    return;
  }
  cout<< root-> data << "";
  preorderTraversal (root-> left);
  preorderTraversal (root->right);
}
vector<int> leftview(Node* root){

}

int main(){
}