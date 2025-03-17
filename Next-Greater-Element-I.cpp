class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nge;
        for(int i=0;i<nums1.size();i++){
            int next_greater=-1;
            bool found=false;
            for(int j=0;j<nums2.size();j++){
                if(nums2[j]==nums1[i]){
                    found=true;
                }
                if(found && nums2[j]>nums1[i]){
                    next_greater=nums2[j];
                    break;
                }
            }
            nge.push_back(next_greater);
        }
        return nge;
    }
};