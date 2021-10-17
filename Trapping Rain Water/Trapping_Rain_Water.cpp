/*
---------------------------------------
QUESTION


Given n non-negative integers representing an height of the building where the width of each building is 1, 
compute how much water it can trap after raining.

SOLUTION

The solution include the use of stack.
----------------------------------------
*/

/*******************CODE*********************/

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
        stack<int> s;
        stack<int> idx;
        int n = height.size();
        int max_v;
        int water = 0;
        for(int j = n-1 ; j >= 0 ; j--){
            while(!s.empty() && height[j] > s.top()){
                max_v = s.top(); 
                idx.pop();
                s.pop();
                if(!s.empty()){
                    water += (min(s.top() , height[j]) - max_v)*(idx.top()-j-1);
                }
            }
            s.push(height[j]);
            idx.push(j);
        }
    return water;
}

int main(){
    vector<int> height = {4,2,0,3,2,5};

    cout << "The trapped water is " << trap(height) << endl;
}