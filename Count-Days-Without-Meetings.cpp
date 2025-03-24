class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
    
    int busyDays = 0;
    int prevEnd = 0;
    
    // Merge overlapping intervals and count busy days
    for (const auto& meeting : meetings) {
        int start = meeting[0], end = meeting[1];
        
        if (start > prevEnd + 1) {
            busyDays += end - start + 1;
        } else if (end > prevEnd) {
            busyDays += end - prevEnd;
        }
        
        prevEnd = max(prevEnd, end);
    }
    
    return days - busyDays;
    }
};