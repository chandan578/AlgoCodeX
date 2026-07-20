#include<bits/stdc++.h>
using namespace std;

/*
Bubble Sort Algorithm
Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted. The algorithm gets its name because smaller elements "bubble" to the top of the list.

Time Complexity: O(n^2)
Space Complexity: O(1)

*/

void bubbleSort(vector<int>& nums){
    
    int n = nums.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(nums[i] < nums[j]){
                swap(nums[i], nums[j]);
            }
        }
    }
}

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    bubbleSort(nums);

    for(auto num : nums){
        cout<<num<<" ";
    }

    return 0;
}