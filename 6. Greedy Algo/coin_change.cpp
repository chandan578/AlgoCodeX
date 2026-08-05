#include <bits/stdc++.h>
using namespace std;

/*
Coin Change Problem using Greedy Algorithm
Coin Change Problem is a classic problem in which we are given a set of coin denominations and a target amount. The goal is to find the minimum number of coins needed to make up that amount. If it is not possible to make the amount with the given denominations, we return -1.

In this code, we are implementing a greedy algorithm to solve the Coin Change problem. The greedy approach works optimally when the coin denominations are canonical (like US coins). However, it may not work for all sets of denominations.

Time Complexity: O(n log n) due to sorting the coin denominations.
Space Complexity: O(1) as we are using a constant amount of extra space.

This also solve using Recursion, Dynamic Programming, and other methods, but the greedy approach is efficient for certain cases.
*/

int greedyCoinChange(vector<int>& coins, int amount)
{
    // Sort in descending order
    sort(coins.begin(), coins.end(), greater<int>());

    int count = 0;

    for(int coin : coins)
    {
        if(amount == 0)
            break;

        int take = amount / coin;   // Maximum coins of this denomination

        count += take;

        amount -= take * coin;
    }

    if(amount != 0)
        return -1;      // Cannot make the amount

    return count;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 9;

    cout << greedyCoinChange(coins, amount) << endl;

    return 0;
}