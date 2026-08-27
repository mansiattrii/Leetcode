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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;    // used to store level -> vertical -> set of nodes. map sets it to sorted.
        queue<pair<TreeNode*, pair<int,int>>> todo;   //used for bfs traversal: to store node, level(x-coord) and vertical(y-coord) together.
        todo.push({root, {0,0}});

        //run bfs to calculate {node, {level, vertical}}. 
        while(!todo.empty()){
            auto curr = todo.front();
            todo.pop();

            int x = curr.second.first, y = curr.second.second;
            nodes[x][y].insert(curr.first -> val);

            if(curr.first -> left){
                todo.push({curr.first -> left, {x-1, y+1}});
            }
            if(curr.first -> right){
                todo.push({curr.first -> right, {x+1, y+1}});
            } 
        }

        vector<vector<int>> ans;

        for(auto p : nodes){    //
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};