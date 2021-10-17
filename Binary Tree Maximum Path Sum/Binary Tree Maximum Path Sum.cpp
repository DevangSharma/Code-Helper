/*QUES
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any path.

 */

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

 /************************************CODE*******************************************/
class Solution {
public:
    
    int maxSum(TreeNode * root,int &res){
        
        if(root==NULL){
            return 0;
        }
        
        int l = maxSum(root->left,res);
        int r = maxSum(root->right,res);
        
        
        int temp = max(max(l,r)+root->val,root->val);
        int ans = max(l+r+root->val,temp);
        res = max(res,ans);
        
        return temp;
        
        
    }
    
    int maxPathSum(TreeNode* root) {
        
        int res = INT_MIN ;
        maxSum(root,res);
        return res;
    }
};