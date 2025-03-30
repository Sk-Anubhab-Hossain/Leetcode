class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndex(26, 0);
    
    // Step 1: Store the last occurrence of each character
    for (int i = 0; i < s.size(); i++) {
        lastIndex[s[i] - 'a'] = i;
    }
    
    vector<int> result;
    int start = 0, end = 0;
    
    // Step 2: Iterate through the string and create partitions
    for (int i = 0; i < s.size(); i++) {
        end = max(end, lastIndex[s[i] - 'a']);
        
        if (i == end) {
            result.push_back(end - start + 1);
            start = i + 1;
        }
    }
    
    return result;
    }
};