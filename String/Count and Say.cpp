class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s = countAndSay(n-1);
        int count = 0;
        string ans = "";
        for(int i=0; i<s.size(); i++){
            count++;
            if(i == s.size()-1 || s[i] != s[i+1]){
                ans = ans + to_string(count) + s[i];
                count =0;
            }
        }
        return ans;
    }
};