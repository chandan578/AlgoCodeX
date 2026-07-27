#include <bits/stdc++.h>
using namespace std;

/*

Pruning in Backtracking: Pruning is a technique used in backtracking algorithms to eliminate branches of the search space that are guaranteed not to lead to a valid solution. By identifying and skipping these branches early, we can significantly reduce the number of recursive calls and improve the efficiency of the algorithm.

In this code, we are solving a pathfinding problem on a 7x7 grid. The goal is to find all possible paths from the top-left corner (0,0) to the bottom-left corner (6,0) of the grid, following a specific set of movement rules defined by the input string `path`. The string consists of characters 'U', 'D', 'L', 'R', and '?', where '?' indicates that any direction can be taken at that step.
*/


string path;
bool visited[7][7];
int ans = 0;

void solve(int x, int y, int step)
{
    // Reached destination
    if (x == 6 && y == 0)
    {
        if (step == 48)
            ans++;
        return;
    }

    // Destination reached too early
    if (step == 48)
        return;

    // -------------------------------
    // PRUNING 1 & 2 (Split Grid)
    // -------------------------------

    // Cannot move left/right but both up/down are free
    if ((x == 0 || visited[x - 1][y]) &&
        (x == 6 || visited[x + 1][y]) &&
        y > 0 && !visited[x][y - 1] &&
        y < 6 && !visited[x][y + 1])
        return;

    // Cannot move up/down but both left/right are free
    if ((y == 0 || visited[x][y - 1]) &&
        (y == 6 || visited[x][y + 1]) &&
        x > 0 && !visited[x - 1][y] &&
        x < 6 && !visited[x + 1][y])
        return;

    visited[x][y] = true;

    // -------------------------------
    // PRUNING 3 & 4 (Forced Moves)
    // -------------------------------

    // Move Up
    if ((path[step] == '?' || path[step] == 'U') &&
        x > 0 &&
        !visited[x - 1][y])
    {
        solve(x - 1, y, step + 1);
    }

    // Move Down
    if ((path[step] == '?' || path[step] == 'D') &&
        x < 6 &&
        !visited[x + 1][y])
    {
        solve(x + 1, y, step + 1);
    }

    // Move Left
    if ((path[step] == '?' || path[step] == 'L') &&
        y > 0 &&
        !visited[x][y - 1])
    {
        solve(x, y - 1, step + 1);
    }

    // Move Right
    if ((path[step] == '?' || path[step] == 'R') &&
        y < 6 &&
        !visited[x][y + 1])
    {
        solve(x, y + 1, step + 1);
    }

    visited[x][y] = false;
}

int main()
{
    cin >> path;

    solve(0, 0, 0);

    cout << ans << endl;
}