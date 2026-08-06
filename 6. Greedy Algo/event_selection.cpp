#include<bits/stdc++.h>
using namespace std;

/*
Event Selection Problem using Greedy Algorithm
The Event Selection Problem is a classic problem in which we are given a set of events with their respective start and end times. The goal is to select the maximum number of events that can be attended without overlapping.

Time Complexity: O(n log n) due to sorting the events based on their end times.
Space Complexity: O(1) as we are using a constant amount of extra space.
*/

int eventSelection(vector<pair<int, int>>& events){
    sort(events.begin(), events.end(), [](auto& a, auto& b){
        return a.second < b.second;
    });

    int count = 0;
    int lastTime = 0;
    for(auto& event : events){
        int start = event.first;
        int end = event.second;
        if(start >= lastTime){
            count++;
            lastTime = end;
        }
    }

    return count;
}

int main(){
    vector<pair<int, int>> events = {{1,4},{3,5},{0,6},{5,7},{8,9},{5,9}};
    
    cout<<eventSelection(events);
}


/*
Similar Leetcode Problems:
1. 252. Meeting Rooms
2. 253. Meeting Rooms II
3. 435. Non-overlapping Intervals
4. 452. Minimum Number of Arrows to Burst Balloons
5. 1024. Video Stitching
*/