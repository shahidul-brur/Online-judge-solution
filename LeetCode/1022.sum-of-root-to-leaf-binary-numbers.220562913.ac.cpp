/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const int MOD = 1000000007;
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->val;
        
        int sum = 0;
        if(root->left!=NULL){
            root->left->val = (root->val * 2LL + root->left->val)%MOD;
            sum = sumRootToLeaf(root->left);
        }
        if(root->right!=NULL){
            root->right->val = (root->val * 2LL + root->right->val)%MOD;
            sum = (sum+sumRootToLeaf(root->right))%MOD;
        }
        return sum;
    }
};
