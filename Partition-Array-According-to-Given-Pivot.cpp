class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> smaller;
        vector<int> larger;
        vector<int> same;
        vector<int> res;
        for(int val : nums){
            if(val<pivot){
                smaller.push_back(val);
            }
            else if(val>pivot){
                larger.push_back(val);
            }
            else if(val==pivot){
                same.push_back(val);
            }
        }
        res.insert(res.begin(), smaller.begin(), smaller.end());
        res.insert(res.end(),same.begin(),same.end());
        res.insert(res.end(),larger.begin(),larger.end());
        return res;
    }
};