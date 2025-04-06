class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
    if (n == 0) return {};

    // Sort the numbers to ensure the divisibility condition is easier to manage
    sort(nums.begin(), nums.end());

    // dp[i] = size of the largest subset ending with nums[i]
    vector<int> dp(n, 1);
    // previous index to reconstruct the path
    vector<int> prev(n, -1);

    int maxSize = 1, maxIndex = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxSize) {
            maxSize = dp[i];
            maxIndex = i;
        }
    }

    // Reconstruct the subset
    vector<int> result;
    for (int i = maxIndex; i >= 0; i = prev[i]) {
        result.push_back(nums[i]);
        if (prev[i] == -1) break;
    }

    reverse(result.begin(), result.end());
    return result;
    }
};