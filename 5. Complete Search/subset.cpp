#include<bits/stdc++.h>
using namespace std;

/*
Subset Generation
Given a set of distinct integers, nums, return all possible subsets (the power set).
In that two methods:
1. Using Recursion
2. Using Bit Manipulation

In both methods, the time complexity is O(n*2^n) where n is the number of elements in the input set. This is because there are 2^n possible subsets and for each subset, we may need to iterate through all n elements to construct it.

But best method is using Bit Manipulation because it is more space efficient and does not use the call stack for recursion, which can lead to stack overflow for large input sizes.

*/


// Method 1: Using Recursion 
// Time Complexity: O(n*2^n)
void solve(vector<vector<int>>& ans, vector<int>& nums, vector<int> curr, int idx){
    if(idx == nums.size()){
        ans.push_back(curr);
        return;
    }

    solve(ans, nums, curr, idx+1);
    curr.push_back(nums[idx]);
    solve(ans, nums, curr, idx+1);
    curr.pop_back();
}
vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> curr;
    solve(ans, nums, curr, 0);

    return ans;
}


// Method 2: Using Bit Manipulation
// Time Complexity: O(n*2^n)
vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> ans;

    for(int i=0; i<(1<<nums.size()); i++){
        vector<int> curr ;
        for(int j=0; j<nums.size(); j++){
            // if((i>>j) & 1) // This is also correct
            if(i & (1<<j))
             curr.push_back(nums[j]);
        }

        ans.push_back(curr);
    }

    return ans;
}

int main(){
    vector<int> nums = {10, 20, 30};

    vector<vector<int>> ans = subsets(nums);

    for(auto& num : ans){
        cout<<"( ";
        for(int x : num){
            cout<<x<<" ";
        }
        cout<<")"<<endl;
    }
}