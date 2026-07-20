#include<bits/stdc++.h>
using namespace std;

/*
Sorting STL Uses

Using the sort() function to sort vector, array, string, pair and vector of vectors.
Time Complexity: O(nlogn)
*/


int main(){

    // Using sort() function to sort vector
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    // Sort in Ascending Order
    sort(nums.begin(), nums.end());
    for(auto& num : nums){
        cout<<num<<" ";
    }
    cout<<endl;

    // Using sort() function to sort array
    int n = 9;
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    sort(arr, arr+n);
    for(auto& num : arr){
        cout<<num<<" ";
    }

    // Using sort() function to sort string
    string str = "monkey";
    sort(str.begin(), str.end());
    cout<<endl<<str<<endl;


    // Using sort() function to sort pair and vector of vectors
    vector<pair<int, int>> pairs = {{1,2}, {1,5}, {2, 3}};
    pairs.push_back({0, 1});

    sort(pairs.begin(), pairs.end());
    for(auto& it : pairs){
        cout<<"("<<it.first<<", "<<it.second<<")"<<", ";
    }
    cout<<endl;

    // Using sort() function to sort vector of vectors
    // In this case, the vector of vectors will be sorted based on the first element of each vector. If the first elements are equal, then it will be sorted based on the second element and so on.
    vector<vector<int>> values = {{2, 1, 4}, {1, 5, 3}, {2, 1, 3}};
    values.push_back({1, 5, 2});
    sort(values.begin(), values.end());
    for(auto& it: values){
        cout<<it[0]<<','<<it[1]<<','<<it[2]<<endl;
    }

}