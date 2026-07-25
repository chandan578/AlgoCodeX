#include<bits/stdc++.h>
using namespace std;

/*

N-Queens Problem: Count the number of distinct solutions to the n-queens puzzle.
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens threaten each other. This means that no two queens can be placed in the same row, column, or diagonal.
The solution uses backtracking to explore all possible placements of queens on the board. It keeps track of the columns and diagonals that are already occupied by queens to ensure that no two queens threaten each other.

Time Complexity: O(n!) 
where n is the number of queens (or the size of the chessboard). This is because we are trying to place n queens on the board, and for each queen, we have n choices for the column, leading to n! possible arrangements. However, due to the constraints of the problem (no two queens can be in the same row, column, or diagonal), the actual number of valid arrangements is much less than n!.

*/


void search(int n, int& count, int y, vector<bool>& columns, vector<bool>& dig1, vector<bool>& dig2){
    if(y==n){
        count++;
        return;
    }

    for(int i=0; i<n; i++){
        if(columns[i] || dig1[i+y] || dig2[i-y+n-1]) continue;

        columns[i] = dig1[i+y] = dig2[i-y+n-1] = 1;
        search(n, count, y+1, columns, dig1, dig2);
        columns[i] = dig1[i+y] = dig2[i-y+n-1] = false;
    }
}

int main(){
    int n = 10;

    vector<bool> columns(n, false);
    vector<bool> dig1(2*n, false);
    vector<bool> dig2(2*n, false);

    int count = 0;
    search(n, count, 0, columns, dig1, dig2);

    cout<<count;
}