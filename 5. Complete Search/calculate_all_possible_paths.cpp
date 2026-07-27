#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int totalPaths = 0;

void calculatePath(int n, int curr, int x, int y, vector<vector<bool>>& visited){
    if(x==n-1 && y==n-1){
        if(curr == n*n) totalPaths++;
        return;
    }


    for(auto& it : direction){
        int x_ = it[0]+x;
        int y_ = it[1]+y;
        if(x_>=0 && x_<n && y_>=0 && y_<n && !visited[x_][y_]){
            visited[x_][y_] = true;
            calculatePath(n, curr+1, x_, y_, visited);
            visited[x_][y_] = false;
        }
    }
}


int main(){

    int n = 7;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    // count = 0;
    visited[0][0] = true;

    calculatePath(n, 1, 0, 0, visited);

    cout<<totalPaths<<endl;
}