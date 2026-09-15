class Solution {
public:
    void generate(string curr, int n, vector<string>& ans, int open, int close){
        if(open == n && close == n){
            ans.push_back(curr);
            return;
        }
        if(open < n)    generate(curr + '(', n, ans, open + 1, close);
        if(open > close)    generate(curr + ')', n, ans, open, close + 1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        int open = 0, close = 0;
        generate(curr, n, ans, open, close);
        return ans;
    }
};