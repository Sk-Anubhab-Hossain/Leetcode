class Solution {
public:
    int numRabbits(vector<int>& answers) {
           unordered_map<int, int> count;
    int total = 0;

    for (int ans : answers) {
        count[ans]++;
    }

    for (auto& [k, v] : count) {
        int groupSize = k + 1;
        int groups = ceil((double)v / groupSize);
        total += groups * groupSize;
    }

    return total;
    }
};