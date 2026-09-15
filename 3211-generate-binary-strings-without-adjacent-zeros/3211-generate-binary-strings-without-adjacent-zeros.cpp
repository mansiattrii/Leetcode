class Solution {
public:
    void generate(string curr, vector<string>& ans, int n){
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }

        generate(curr + '1', ans, n);
        if(curr.empty() || curr.back() != '0')  generate(curr + '0', ans, n);
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string curr = "";

        generate(curr, ans, n);
        return ans;
    }
};