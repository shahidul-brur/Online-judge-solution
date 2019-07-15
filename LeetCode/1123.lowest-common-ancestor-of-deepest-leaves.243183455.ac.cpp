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
    int leaf[1004], mxd, mx, rt;
    TreeNode* lca;
    void mx_d(TreeNode* r, int d){
        mxd = max(d, mxd);
        if(r->left==NULL && r->right==NULL) return;
        if(r->left!=NULL) mx_d(r->left, d+1);
        if(r->right!=NULL) mx_d(r->right, d+1);
    }
    
    void dfs(TreeNode* r, int d){
        leaf[r->val] = 0;
        if(r->left==NULL && r->right==NULL){
            if(d==mxd) leaf[r->val]=1;
            return;
        }
        if(r->left!=NULL){
            dfs(r->left, d+1);
            leaf[r->val]+=leaf[r->left->val];
        }
        if(r->right!=NULL){
            dfs(r->right, d+1);
            leaf[r->val]+=leaf[r->right->val];
        }
    }
    
    void dfs2(TreeNode* r, int d){
        if(leaf[rt]==leaf[r->val] && d>mx) lca = r, mx = d;
        if(r->left==NULL && r->right==NULL) return;
        if(r->left!=NULL) dfs2(r->left, d+1);
        if(r->right!=NULL) dfs2(r->right, d+1);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL) return NULL;
        rt = root->val;
        mxd=mx=-1;
        mx_d(root,0);
        dfs(root,0);
        dfs2(root,0);
        return lca;
    }
};
