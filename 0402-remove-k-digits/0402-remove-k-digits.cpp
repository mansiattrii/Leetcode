class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() <= k) return "0";
        stack<char> st;

        //add numbers in non decreasing 
        for(int i = 0; i < num.size(); i++){
            while(!st.empty() && st.top() > num[i] && k > 0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        //if not all k digits are removed
        while(k>0){
            st.pop();
            k--;
        }

        if(st.empty())  return "0";

        string res = "";

        //storing the digits in reverse:
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        //removing trailing zeroes:
        while(res.size() > 0 && res.back() == '0'){
            res.pop_back();
        }
        if(res.empty()) return "0";
        
        //reversing the "res" string
        reverse(res.begin(), res.end());
        
        return res;
    }
};