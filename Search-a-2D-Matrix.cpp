class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row= matrix.size();
        int col=matrix[0].size();
        int left=0, right=(row*col)-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            int midvalue= matrix[mid/col][mid%col];//[mid/col] finds row number and [mid%col]   finds col number

            if(midvalue==target) return true;
            else if(target>midvalue) left=mid+1;
            else right=mid-1;
        }
        return false;

    }
};