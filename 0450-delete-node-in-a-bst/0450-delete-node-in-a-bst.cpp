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
    TreeNode* helper(TreeNode* node){
        if(node -> left == NULL)    return node -> right;
        else if(node -> right == NULL)  return node -> left;

        TreeNode* leftChild = node -> left;
        TreeNode* leftMostChild = node -> right;
        while(leftMostChild -> left){
            leftMostChild = leftMostChild -> left;
        }
        leftMostChild -> left = leftChild;

        return node -> right;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)    return NULL;
        if(root -> val == key)  return helper(root);
        TreeNode* dummy = root;

        while(root){
            if(root -> val > key){      //key might be in left subtree
                if(root -> left && root -> left -> val == key)
                    root -> left = helper(root -> left);
                else
                    root = root -> left;
            }
            else if(root -> val < key){
                if(root -> right && root -> right -> val == key)
                    root -> right = helper(root -> right);
                else
                    root = root -> right;
            }
            
        }        

        return dummy;
    }
};