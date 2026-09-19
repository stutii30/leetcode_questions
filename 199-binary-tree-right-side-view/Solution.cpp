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
vector<int>ans;
void solve(TreeNode* root, int level){
    if(root==NULL) return;
    if(level==ans.size())
    ans.push_back(root->val);
    solve(root->right,1+level);
    solve(root->left,1+level);
}
    vector<int> rightSideView(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};