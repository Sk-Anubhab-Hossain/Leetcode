class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curr_sum_max=0;
        int curr_sum_min=0;
        int min_sum=INT_MAX;
        int max_sum=INT_MIN;
        int total=0;
        int n=nums.size();
        for(int num : nums){
            curr_sum_min=min(num, curr_sum_min+num);
            min_sum=min(min_sum,curr_sum_min);

            curr_sum_max=max(num, curr_sum_max+num);
            max_sum=max(max_sum,curr_sum_max);

            total+=num;
        }
        return (max_sum<0) ? max_sum : max(max_sum, total-min_sum);
    }
};