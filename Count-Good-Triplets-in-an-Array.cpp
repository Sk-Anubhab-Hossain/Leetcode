class FenwickTree {
public:
    vector<int> tree;
    int size;

    FenwickTree(int n) {
        size = n;
        tree.assign(n + 1, 0);
    }

    void update(int index, int delta) {
        for (++index; index <= size; index += index & -index)
            tree[index] += delta;
    }

    int query(int index) {
        int sum = 0;
        for (++index; index > 0; index -= index & -index)
            sum += tree[index];
        return sum;
    }

    int query(int left, int right) {
        return query(right) - query(left - 1);
    }
};
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
    vector<int> pos2(n);
    for (int i = 0; i < n; ++i)
        pos2[nums2[i]] = i;

    vector<int> mappedNums(n);
    for (int i = 0; i < n; ++i)
        mappedNums[i] = pos2[nums1[i]];

    FenwickTree bitLeft(n), bitRight(n);
    vector<int> leftCount(n), rightCount(n);

    // Count how many numbers before i are less than mappedNums[i]
    for (int i = 0; i < n; ++i) {
        leftCount[i] = bitLeft.query(mappedNums[i] - 1);
        bitLeft.update(mappedNums[i], 1);
    }

    // Count how many numbers after i are greater than mappedNums[i]
    for (int i = n - 1; i >= 0; --i) {
        rightCount[i] = bitRight.query(n - 1) - bitRight.query(mappedNums[i]);
        bitRight.update(mappedNums[i], 1);
    }

    long long total = 0;
    for (int i = 0; i < n; ++i)
        total += (long long)leftCount[i] * rightCount[i];

    return total;
    }
};