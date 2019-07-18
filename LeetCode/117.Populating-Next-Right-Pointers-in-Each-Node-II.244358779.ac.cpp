/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    void dfs(Node* u, Node* nxt){
        u->next = nxt;
        //int v = nxt==NULL?-1:nxt->val;
        //int lft=-1, rgt=-1;
        //if(u->left!=NULL) lft = u->left->val;
        //if(u->right!=NULL) rgt = u->right->val;
        //cout << u->val << ", " << lft << ", " << rgt << ": ";
        //cout << v << "\n";
        if(u->right!=NULL){
            Node* nx=NULL;
            Node* tnxt = nxt;
            while(nx==NULL && tnxt!=NULL){
                if(tnxt->left!=NULL){
                    nx = tnxt->left;
                    break;
                }
                else if(tnxt->right!=NULL){
                    nx = tnxt->right;
                    break;
                }
                else tnxt = tnxt->next;
            }
            dfs(u->right, nx);
        }
        if(u->left!=NULL){
            Node* nx = NULL;
            if(u->right!=NULL)
                nx = u->right;
            else{
                while(nx==NULL && nxt!=NULL){
                    if(nxt->left!=NULL){
                        nx = nxt->left;
                        break;
                    }
                    else if(nxt->right!=NULL){
                        nx = nxt->right;
                        break;
                    }
                    else nxt=nxt->next;
                }
            }
            dfs(u->left, nx);
        }
    }
    Node* connect(Node* root) {
        if(root==NULL) return root;
        dfs(root, NULL);
        return root;
    }
};
