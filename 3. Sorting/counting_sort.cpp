#include<bits/stdc++.h>
using namespace std;


/*
Counting Sort Algorithm
Counting Sort is a non-comparison based sorting algorithm that sorts the elements of an array by counting the number of occurrences of each unique element in the array. The count is stored in an auxiliary array and the sorted output is generated from this count array.
Time Complexity: O(n+k) where n is the number of elements in the input array and k is the range of the input values.
Space Complexity: O(k) where k is the range of the input values.

*/


vector<int> countingSort(vector<int>& nums){
    int maxNum = *max_element(nums.begin(), nums.end());

    vector<int> count(maxNum+1);

    for(int i=0; i<nums.size(); i++){
        count[nums[i]]++;
    }

    vector<int> ans ;
    for(int i=0; i<count.size(); i++){
        while(count[i] != 0) {
            ans.push_back(i);
            count[i]--;
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {1, 3, 6, 9, 9, 3, 5, 9};

    vector<int> ans = countingSort(nums);

    for(auto& num : ans){
        cout<<num<<" ";
    }

    return 0;
}