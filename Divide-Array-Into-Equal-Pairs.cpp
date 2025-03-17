class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int count_of_num=0;
        for(int i=0;i<nums.size();i++){
            // count_of_num=0;
            for(int num : nums){
                if(num==nums[i]){
                    count_of_num++;
                }
            }
            if(count_of_num %2 !=0) return false;
        }
        return true;
    }
};