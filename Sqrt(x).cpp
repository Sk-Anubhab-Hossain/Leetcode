class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) 
            return x;

        int left = 0, right = x, ans = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2; // Avoid overflow
            long long square = mid * mid;

            if (square == x)
                return mid;
            else if (square < x) {
                ans = mid;  // Store potential answer
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};