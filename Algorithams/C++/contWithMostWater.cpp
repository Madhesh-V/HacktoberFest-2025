#include<iostream>
using namespace std;

//conatiner with most water 
//Brute force solution
void bruteForce(){
    int h[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int maxWater = 0;
    for(int i = 0; i < 9; i++){
        for(int j = i + 1; j < 9; j++){
            int width = j - i;
            int height = min(h[i], h[j]);
            int area = width * height;
            maxWater = max(maxWater, area);
        }
    }
    cout<<"Container with maximum water is: "<<maxWater<<endl;
}

//Optimal solution 
//Solved by using two pointer approach
void optimalForce(){
  int h[9] = {1, 8, 6, 2, 5, 4, 8, 3, 6};
  int maxWater = 0;
  int left = 0, right = 8;
  while(left < right){
    int width = right - left;
    int height = min(h[left], h[right]);
    int area = width * height;
    maxWater = max(maxWater, area);
    left < right ? left++ : right--;
  }
  cout<<"Container with maximum water is: "<<maxWater<<endl;
}


int main(){
    bruteForce(); //Time complexity of O(n^2);
    optimalForce(); //Time complexity of O(n), by using 2 pointer approach
    return 0;
}