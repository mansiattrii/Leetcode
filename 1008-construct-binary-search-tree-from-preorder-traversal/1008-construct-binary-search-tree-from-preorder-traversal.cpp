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
    void insertBST(TreeNode* root, int& num){
        while(root){
            if(num < root -> val){
                if(!root -> left){
                    root -> left = new TreeNode(num);
                    return;
                }
                else
                    root = root -> left;
            }

            else{
                if(!root -> right){
                    root -> right = new TreeNode(num);
                    return;
                }
                else
                    root = root -> right;
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i < preorder.size(); i++){
            TreeNode* dummy = root;
            insertBST(dummy, preorder[i]);
        }
        return root;
    }
};