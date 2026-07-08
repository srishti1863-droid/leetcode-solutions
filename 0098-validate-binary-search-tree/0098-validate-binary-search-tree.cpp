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
   long long a=LLONG_MIN;
   long long b=LLONG_MAX;
bool isValidBST(TreeNode* root,long long a,long long b){
    if(root==NULL) return true;
    if(root->val>=b||root->val<=a) return false;
    return isValidBST(root->left,a,root->val) && isValidBST(root->right,root->val,b);
}
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,a,b);
    }
};