class Solution {
  public:
    string longestPalin (string S) {
        // code here
        int s=0,e=0;
        bool f = false;
        int maxLength=0;
        for(int i=0; i<S.size(); i++){
            int len1 = expand(S,i,i+1);
            int len2 = expand(S,i,i);
            int len = max(len1,len2);
            if(len>1){
                f = true;
            }
            if (len > maxLength) {
                s = i - (len - 1) / 2;
                e = i + len / 2;
                maxLength = len; // Update maximum length
                f = true; // Mark that we found a palindrome
            }
        }
        if(!f){
            return S.substr(0,1);
        }
        return S.substr(s,e-s+1);
    }
    int expand(string s,int i,int j){
        while(i>=0 && j<s.size() && s[i] == s[j]){
            i--,j++;
        }
        return j-i-1;
    }
};s