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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderHelper(root,result);
        return result;

    }
private:
    void preorderHelper(TreeNode* root, vector<int>& result){
        if(root==nullptr) return;
    //     result.push_back(root->val);
    //     preorderHelper(root->left,result);
    //     preorderHelper(root->right,result);

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            result.push_back(node->val);

            if(node->right){
                st.push(node->right);
            }
            if(node->left){
                st.push(node->left);
            }

        }
    }
};