class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
         set<int> xSet, ySet;
        
        // Collect unique x and y coordinates
        for (const auto& rect : rectangles) {
            xSet.insert(rect[0]); // startx
            xSet.insert(rect[2]); // endx
            ySet.insert(rect[1]); // starty
            ySet.insert(rect[3]); // endy
        }
        
        vector<int> xCoords(xSet.begin(), xSet.end());
        vector<int> yCoords(ySet.begin(), ySet.end());
        
        // Check vertical cuts
        if (canMakeValidCuts(xCoords, rectangles, true)) return true;
        
        // Check horizontal cuts
        if (canMakeValidCuts(yCoords, rectangles, false)) return true;
        
        return false;
    }
    
private:
    bool canMakeValidCuts(vector<int>& coords, vector<vector<int>>& rectangles, bool isVertical) {
        vector<pair<int, int>> events;
        
        // Collect events (start and end positions)
        for (const auto& rect : rectangles) {
            int start = isVertical ? rect[0] : rect[1];
            int end = isVertical ? rect[2] : rect[3];
            events.push_back({start, 1});  // +1 for start of a rectangle
            events.push_back({end, -1});   // -1 for end of a rectangle
        }
        
        // Sort events: First by position, then by type (-1 before +1 to avoid premature split)
        sort(events.begin(), events.end());

        int activeCount = 0;
        int sections = 0;
        for (const auto& event : events) {
            activeCount += event.second;
            if (activeCount == 0) {
                sections++;  // Valid section found
                if (sections == 3) return true;  // Three valid sections found
            }
        }

        return false;
    }
};