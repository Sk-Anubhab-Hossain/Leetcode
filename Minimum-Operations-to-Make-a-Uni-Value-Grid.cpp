class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> values;
    int m = grid.size(), n = grid[0].size();
    
    // Flatten grid into a 1D vector
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            values.push_back(grid[i][j]);
        }
    }
    
    // Check if it's possible to make all elements equal
    int remainder = values[0] % x;
    for (int val : values) {
        if (val % x != remainder) return -1;
    }
    
    // Sort values and find the median
    sort(values.begin(), values.end());
    int median = values[values.size() / 2];
    
    // Compute the minimum operations
    int operations = 0;
    for (int val : values) {
        operations += abs(val - median) / x;
    }
    
    return operations;
    }
};