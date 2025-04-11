class Solution {
public:
    bool isSymmetric(int num) {
    string s = to_string(num);
    int len = s.length();
    if (len % 2 != 0) return false; // Not even number of digits

    int mid = len / 2;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < mid; ++i) {
        sum1 += s[i] - '0';
        sum2 += s[i + mid] - '0';
    }
    return sum1 == sum2;
    }

    int countSymmetricIntegers(int low, int high) {
    int count = 0;
    for (int i = low; i <= high; ++i) {
        if (isSymmetric(i)) {
            count++;
        }
    }
    return count;
    }
};