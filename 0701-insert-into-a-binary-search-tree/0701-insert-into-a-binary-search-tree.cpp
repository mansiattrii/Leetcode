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
    void insert(TreeNode* node, int val){
        if(node -> val > val){
            if(node -> left)    insert(node -> left, val);
            else{
                node -> left = new TreeNode(val); 
            }
        }
        else{
            if(node -> right)    insert(node -> right, val);
            else{
                node -> right = new TreeNode(val); 
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            root = new TreeNode(val);
            return root;
        };
        insert(root, val);
        return root;
    }
};