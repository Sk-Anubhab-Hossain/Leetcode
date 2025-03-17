class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n, -1);
        // sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n+i;j++){
                if(nums[j%n]>nums[i]){
                    nge[i]=nums[j%n];
                    break;
                }
            }
        }
        return nge;
    }
};