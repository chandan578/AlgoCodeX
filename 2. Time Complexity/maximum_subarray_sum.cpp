#include<bits/stdc++.h>
using namespace std;

/*
Maximum Subarray Sum Problem
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Three Approaches to solve this problem:
1. Brute Force Approach: O(n^3)
2. Better Approach: O(n^2)
3. Optimal Approach: O(n) - Kadane's Algorithm

*/

// Brute Force Approach: O(n^3)
int maxSubArray(vector<int>& nums){
    int maxSum = INT_MIN;
    int n = nums.size();

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum += nums[k];
            }
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}


// Better Approach: O(n^2)
int maxSubArray(vector<int>& nums){
    int maxSum = INT_MIN;
    int n = nums.size();

    for(int i=0; i<n; i++){
        int sum = 0;

        for(int j=i; j<n; j++){
            sum += nums[j];
            maxSum = max(sum, maxSum);
        }
    }

    return maxSum;
}

// Optimal Approach: O(n) - Kadane's Algorithm
int maxSubArray(vector<int>& nums){
    int maxSum = INT_MIN;
    int sum = 0;
    int n = nums.size();

    for(int i=0; i<n; i++){
        sum = max(nums[i], sum+nums[i]);
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}



int main(){
    
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout<<maxSubArray(nums);

    return 0;
}