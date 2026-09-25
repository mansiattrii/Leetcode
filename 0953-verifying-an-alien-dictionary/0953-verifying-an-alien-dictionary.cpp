class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int orderInd[26];
        for(int i=0; i<26; i++){
            orderInd[order[i]-'a'] = i;
        }

        auto compare = [&] (const string &a, const string& b){
            for(int i=0; i<min(a.size(), b.size()); i++){
                if(a[i] != b[i]){
                    return orderInd[a[i] - 'a'] < orderInd[b[i] - 'a'];
                }
            }
            return a.size() < b.size();
        };

        return is_sorted(words.begin(), words.end(), compare);
    }
};