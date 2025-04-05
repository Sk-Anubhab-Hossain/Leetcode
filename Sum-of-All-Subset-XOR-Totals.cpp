class Solution {
private:
    int helper(vector<int>& nums, int index, int XOR){
        if(index==nums.size()){
            return XOR;
        }
        int include= helper(nums, index+1, XOR^nums[index]);
        int exclude= helper(nums, index+1, XOR);
        return include+exclude;
    }
public:
    int subsetXORSum(vector<int>& nums) {
       return helper(nums,0,0);
    }
};