#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:

int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    queue<pair<int, pair<int, int>>> q;
    int fresh_oranges = 0;

    // Initialize queue with all rotten oranges and count fresh oranges
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (grid[r][c] == 2) {
                q.push({0, {r, c}}); // {time, {row, col}}
            } else if (grid[r][c] == 1) {
                fresh_oranges++;
            }
        }
    }

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minutes = 0;

    // BFS traversal
    while (!q.empty()) {
        auto [time, cell] = q.front();
        q.pop();
        int r = cell.first, c = cell.second;
        minutes = time;

        for (auto [dr, dc] : directions) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                grid[nr][nc] = 2;
                fresh_oranges--;
                q.push({time + 1, {nr, nc}});
            }
        }
    }

    return fresh_oranges == 0 ? minutes : -1; // Return -1 if some fresh oranges remain
}

};