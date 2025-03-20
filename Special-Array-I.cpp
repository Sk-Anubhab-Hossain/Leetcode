class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1){
            return true;
        }
        for(int first=0; first<n-1;first++){
            int second=first+1;
            if(((nums[first]%2!=0) && (nums[second]%2!=0)) || ((nums[first]%2==0) && (nums[second]%2==0))){
                return false;
            }
        }
        return true;
    }
};