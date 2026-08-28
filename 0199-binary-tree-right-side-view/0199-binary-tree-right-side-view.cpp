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
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root)   return ans;
        map<int, int> mpp;  //mpp.first = level, mpp.second = node's value.
        queue<pair<TreeNode*, int>> que;

        que.push({root, 0});

        while(!que.empty()){
            pair<TreeNode*, int> cur = que.front();
            que.pop();

            mpp[cur.second] = cur.first -> val;
            if(cur.first -> left)   que.push({cur.first -> left, cur.second + 1});
            if(cur.first -> right)  que.push({cur.first -> right, cur.second + 1});
        }

        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};