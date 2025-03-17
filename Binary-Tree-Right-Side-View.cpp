/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void bfs(TreeNode* root, int level, vector<vector<int>> &res){
        if(!root){
            return;
        }
        if(res.size()<=level){
            res.push_back({});
        }
        res[level].push_back(root->val);
        bfs(root->left,level+1,res);
        bfs(root->right,level+1,res);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> res1;
        bfs(root,0,res);
        for(int i=0;i<res.size();i++){
            res1.push_back(res[i][res[i].size()-1]);
        }
        return res1;
    }
};