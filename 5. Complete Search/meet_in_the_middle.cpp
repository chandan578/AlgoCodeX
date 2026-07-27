#include <bits/stdc++.h>
using namespace std;

/*
Meet in the Middle Algorithm
This algorithm is a powerful technique used to solve problems that can be divided into two halves. It is particularly useful for problems where the input size is too large for a brute-force solution, but can be split into two smaller subproblems that can be solved independently.

Before time complexity: O(2^n)
After applying Meet in the Middle: O(2^(n/2) * log(2^(n/2))) = O(2^(n/2) * n)

In this code, we are solving the Subset Sum problem using the Meet in the Middle technique
*/

vector<long long> generateSubsetSums(vector<int>& arr)
{
    int n = arr.size();

    vector<long long> sums;

    for(int mask = 0; mask < (1 << n); mask++)
    {
        long long sum = 0;

        for(int i = 0; i < n; i++)
        {
            if(mask & (1 << i))
                sum += arr[i];
        }

        sums.push_back(sum);
    }

    return sums;
}

bool meetInMiddle(vector<int>& nums, long long target)
{
    int n = nums.size();

    int mid = n / 2;

    vector<int> left(nums.begin(), nums.begin() + mid);
    vector<int> right(nums.begin() + mid, nums.end());

    vector<long long> leftSums = generateSubsetSums(left);
    vector<long long> rightSums = generateSubsetSums(right);

    sort(rightSums.begin(), rightSums.end());

    for(long long leftSum : leftSums)
    {
        long long need = target - leftSum;

        if(binary_search(rightSums.begin(), rightSums.end(), need))
            return true;
    }

    return false;
}

int main()
{
    vector<int> nums = {3, 34, 4, 12, 5, 2};

    long long target = 9;

    if(meetInMiddle(nums, target))
        cout << "Subset Exists\n";
    else
        cout << "Subset Doesn't Exist\n";
}


/*
Related Leetcode Problems:
1755
2035
805
*/