class Solution {
public:
    long long helper(string& s, int ind, long long num){
        if(ind == s.size() || !isdigit(s[ind])) return num;

        num = num * 10 + (s[ind] - '0');

        if(num > INT_MAX)   return num;
        return helper(s, ind + 1, num);
    }
    int myAtoi(string s) {
        int i = 0, n = s.size();
        while(i < n && s[i] == ' ') i++;

        int sign = 1;
        if(i<n && (s[i] == '+' || s[i] == '-')){
            if(s[i] == '-') sign = -1;
            i++;
        }
        long long res = helper(s, i, 0);
        res *= sign;

        if(res < INT_MIN)   return INT_MIN;
        if(res > INT_MAX)   return INT_MAX;    
        return (int) res;
    }
};