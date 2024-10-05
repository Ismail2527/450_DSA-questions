class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = indices.size();
        vector<char>ch(n);
        for(int i=0; i<n; i++){
            char c = s[i];
            ch[indices[i]].push_back(c)
        }
        string ans ;
        for(int i=0; i<n; i++){
            ans = ans + ch[i];
        }
        return ans;
    }
};