// calculate height of a binary tree
//.....O(N).........
class TreeNode{
    public:
    int data;
    TreeNode*left;
    TreeNode*right;
    TreeNode(){
        left=right=NULL;
    }
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
};
// min depth of a BT
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        if(min(left,right)==0)return 1+max(left,right);
        else return 1+min(left,right);
    }
};