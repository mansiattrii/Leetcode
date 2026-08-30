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
    int result;
    void inorder(TreeNode* node, int& k){
        if(node){
            inorder(node -> left, k);
            if(--k == 0)
            {
                result = node -> val;
                return;
            }
            inorder(node -> right, k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        this -> result = -1;
        inorder(root, k);
        return result;
    }
};