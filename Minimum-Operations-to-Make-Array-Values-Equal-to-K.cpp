class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int min=nums[0];
        if(min<k) return -1;
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]>k){
                count++;
                while(i+1<n && nums[i]==nums[i+1]){
                    i++;
                }
            }
        }
        return count;
    }
};