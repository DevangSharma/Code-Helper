/*QUES

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

*/



/****************************************************************************************************/

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
 /*****************************************************CODE**************************************************/
class Solution {
public:
    
    void flat(TreeNode* root){
        
        if(root==NULL || (root->left==NULL && root->right==NULL))
            return;
        
        if(root->left!=NULL){
            flat(root->left);
            
            TreeNode * temp;
            temp = root->right;
            root->right = root->left;
            root->left = NULL;
            
            
            TreeNode *t = root->right;
            while(t->right!=NULL){
                t = t->right;
            }
            
            t->right = temp;  
        }
        
        flat(root->right);
        
    }
    
    void flatten(TreeNode* root) {
        flat(root);
    }
};