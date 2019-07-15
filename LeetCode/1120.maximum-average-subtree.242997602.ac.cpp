/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    double tot[5004], cnt[5004], mx=0.0;
    void dfs(TreeNode* root, int u){
        if(root==NULL) return;
        tot[u] = root->val;
        cnt[u] = 1;
        int v = u;
        if(root->left!=NULL){
            ++v;
            dfs(root->left, v);
            cnt[u]+=cnt[v];
            tot[u]+=tot[v];
        }
        if(root->right!=NULL){
            ++v;
            dfs(root->right, v);
            cnt[u]+=cnt[v];
            tot[u]+=tot[v];
        }
        mx = max(mx, tot[u]/cnt[u]);
    }
    double maximumAverageSubtree(TreeNode* root) {
        mx = 0.0;
        dfs(root,1);
        return mx;
    }
};
