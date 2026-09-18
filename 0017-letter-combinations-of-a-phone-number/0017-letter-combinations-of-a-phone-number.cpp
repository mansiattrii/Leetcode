class Solution {
public:
    void rec(int ind, string s, string digits, vector<string>& ans, string combo[]){
        if(ind == digits.size()){
            ans.push_back(s);
            return;
        }
        //convert digit(char) to digit(int):
        int digit = digits[ind] - '0';
        for(int i = 0; i<combo[digit].size(); i++){
            rec(ind+1, s+combo[digit][i], digits, ans, combo);
        }
    }
    vector<string> letterCombinations(string digits) {
        string combo[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string s;
        rec(0, s, digits, ans, combo);
        return ans;
    }
};