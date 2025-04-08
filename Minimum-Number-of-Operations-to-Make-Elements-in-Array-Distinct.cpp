class Solution {
private:
    bool hasduplicate(vector<int> nums){
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    return true;
                    break;
                }
            }
        }
        return false;
    }
public:
    int minimumOperations(vector<int>& nums) {
        int count=0;
        while(hasduplicate(nums)){
            int removecount=min(3,(int)nums.size());
            nums.erase(nums.begin(), nums.begin()+removecount);
            count++;
        }
        return count;
    }
};