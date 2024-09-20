#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int countBuildings(vector<int> &height){
  int maxHeight = height[0];
  int count =1;
  if (height.empty()) return 0;
  for ( int i = 1; i< height.size(); i++){
    if ( height[i] > maxHeight){
      count ++;
      maxHeight = height[i];
    }
  }
  return count;
  
}
int main() {
    vector<int> height = {2, 3, 1, 5}; // Example input
    cout << "Number of buildings that can see the sunrise: " 
              << countBuildings(height) << std::endl;
    return 0;
}