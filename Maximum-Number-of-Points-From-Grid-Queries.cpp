class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
    int k = queries.size();
    
    vector<int> sorted_queries = queries;  // Copy queries to sort
    sort(sorted_queries.begin(), sorted_queries.end());

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<int> answer(k, 0);
    unordered_map<int, int> result_map; // Map query value to computed results

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    pq.push({grid[0][0], {0, 0}}); // Start from top-left
    visited[0][0] = true;

    int count = 0;
    vector<int> dir = {-1, 0, 1, 0, -1}; // For 4-direction movement

    for (int query : sorted_queries) {
        // Process all cells in the heap that are smaller than the current query
        while (!pq.empty() && pq.top().first < query) {
            auto [val, pos] = pq.top();
            pq.pop();
            int x = pos.first, y = pos.second;
            count++; // Increase count for first-time visited cells

            // Explore all 4 directions
            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d], ny = y + dir[d + 1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    pq.push({grid[nx][ny], {nx, ny}});
                }
            }
        }
        result_map[query] = count; // Store the computed result
    }

    // Map results back to the original query order
    for (int i = 0; i < k; i++) {
        answer[i] = result_map[queries[i]];
    }

    return answer;
    }
};