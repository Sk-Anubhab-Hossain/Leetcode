class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0, e = n - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2; // Calculate mid in every iteration
            
            if (nums[mid] == target) {
                return mid;
            }
            if(nums[s]<=nums[mid]){//left half is sorted
                if(nums[s]<=target && target<=nums[mid]){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            else {//right half is sorted
                if(nums[e]>=target && target>nums[mid]){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }
        }
        return -1;
    }
};