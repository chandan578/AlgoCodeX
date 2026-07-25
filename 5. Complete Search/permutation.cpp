#include<bits/stdc++.h>
using namespace std;


/*
Generate all permutations of a given array of numbers.

Three different approaches are implemented here:
1. Backtracking with a boolean array to keep track of chosen elements.
2. Backtracking with swapping elements in the array.
3. Using the next_permutation function from the STL after sorting the array.
*/


// Approach 1: Backtracking with a boolean array
// Time Complexity: O(n! * n) where n is the number of elements in the array.
void permut(vector<int>& nums, vector<bool>& choosen, vector<int> curr, vector<vector<int>>& ans){
    if(curr.size()== nums.size()){
        ans.push_back(curr);
        return;
    }

    for(int i=0; i<nums.size(); i++){
        if(choosen[i]) continue;

        choosen[i] = true;
        curr.push_back(nums[i]);
        permut(nums, choosen, curr, ans);
        choosen[i] = false;
        curr.pop_back();
    }
}


// Approach 2: Backtracking with swapping
// Time Complexity: O(n! * n) where n is the number of elements in the array.
void permut(vector<int>& nums, int idx, vector<vector<int>>& ans){
    if(idx == nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int i=idx; i<nums.size(); i++){
        swap(nums[i], nums[idx]);
        permut(nums, idx+1, ans);
        swap(nums[i], nums[idx]);
    }
}


// Approach 3: Using next_permutation
// Time Complexity: O(n! * n) where n is the number of elements in the array.
void permut(vector<int>& nums, int idx, vector<vector<int>>& ans){
    sort(nums.begin(), nums.end());

    do{
        ans.push_back(nums);

    }while(next_permutation(nums.begin(), nums.end()));
    // Note: This approach generates permutations in lexicographical order and requires the input array to be sorted first.
    // next_permutation time complexity is O(n) and it generates the next permutation in place, so the overall time complexity is O(n! * n).
}



int main(){
    vector<int> nums = {1, 2, 3};

    int n = nums.size();
    vector<bool> chossen(n, false);
    
    vector<vector<int>> ans;
    // permut(nums, chossen, {}, ans);
    permut(nums, 0, ans);

    for(auto& x : ans){
        cout<<"( ";
        for(int val : x){
            cout<<val<<" ";
        }
        cout<<"), ";
    }
}