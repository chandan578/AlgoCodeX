#include<bits/stdc++.h>
using namespace std;

/*
Scheduling Tasks Problem using Greedy Algorithm
The Scheduling Tasks Problem is a classic problem in which we are given a set of tasks with their respective compilation times. The goal is to find the minimum total compilation time by scheduling the tasks optimally.

Time Complexity: O(n log n) due to sorting the compilation times.
Space Complexity: O(1) as we are using a constant amount of extra space.
*/

int minCompilationTime(vector<int>& time){
    sort(time.begin(), time.end());

    int currTime = 0;
    int totalTime = 0;
    for(int t : time){
        currTime += t;
        totalTime += currTime;
    }

    return totalTime;
}

int main(){
    vector<int> time = {4,2,3,1};
    
    cout<<"Total Compilation Time: "<<minCompilationTime(time);

}