class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos_count=0, neg_count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) neg_count++;
            else if(nums[i]==0) continue;
            else pos_count++;
        }
        return max(neg_count,pos_count);
    }
};