class Solution {
int digitSum(int num) {
    int sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> countMap;
    int maxSize = 0;

    for (int i = 1; i <= n; ++i) {
        int sum = digitSum(i);
        countMap[sum]++;
        maxSize = max(maxSize, countMap[sum]);
    }

    int result = 0;
    for (auto& entry : countMap) {
        if (entry.second == maxSize) {
            result++;
        }
    }

    return result;
    }
};