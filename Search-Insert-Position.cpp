class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // int pos;

        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==target){
        //         pos=i;
        //         break;
        //     }
        //     else{
        //         if(nums[i]<target) pos=i;
        //     }
        // }
        // return pos;

        int left=0, right=nums.size()-1;
        while(left<=right){
            int mid= (left+right)/2;

            if(nums[mid]==target){
                return mid;;
            }
            else if(target>nums[mid]){
                left=mid+1;
            }
            else if(target<nums[mid]){
                right=mid-1;
            }
        }
        return left;
    }
};