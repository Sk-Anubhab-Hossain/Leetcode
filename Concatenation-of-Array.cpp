class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // int n=nums.size();
        // vector<int> ans(2*n);
        // for(int i=0;i<n;i++){
        //     ans[i]=nums[i];
        //     ans[i+n]=nums[i];
        // }
        // return ans;
        nums.insert(nums.begin(), nums.begin(), nums.end());//  as the final vector is 2 time repetition of the original vector.
        return nums;
    }
};