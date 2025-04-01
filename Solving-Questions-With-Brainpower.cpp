class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
    vector<long long> dp(n + 1, 0); // DP array to store max points
    
    for (int i = n - 1; i >= 0; --i) {
        int points = questions[i][0];
        int jump = questions[i][1];
        // Option 1: Solve this question
        long long solve = points + (i + jump + 1 < n ? dp[i + jump + 1] : 0);
        // Option 2: Skip this question
        long long skip = dp[i + 1];
        // Take the max of both choices
        dp[i] = max(solve, skip);
    }
    
    return dp[0];
    }
};