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
    vector<TreeNode*> ans;
    bool del[1005];
    void dfs(TreeNode* u, int in){
        if(u==NULL) return;
            if(!del[u->val] && in==1) ans.push_back(u);
        dfs(u->left, del[u->val]);
        dfs(u->right, del[u->val]);
        if(u->left!=NULL && del[u-> left->val]) u-> left = NULL;
            
         if(u->right!=NULL && del[u->right->val]) u->right = NULL;
        }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& d) {
        memset(del,0,sizeof(del));
        for(int x:d) del[x]=1; 
        dfs(root,1);
        return ans;
    }
};
