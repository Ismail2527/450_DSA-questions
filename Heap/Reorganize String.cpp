class Solution {
public:
    char getMaxCountChar(vector<int>& countArray) {
    int max = 0;
    char ch = '\0';
    for (int i = 0; i < 26; i++) {
        if (countArray[i] > max) {
            max = countArray[i];
            ch = 'a' + i;
        }
    }
    return ch;
}

string rearrangeString(string s) {
    vector<int> countArray(26, 0);
    int n = s.length();
    
    for (char c : s) {
        countArray[c - 'a']++;
    }

    char c = getMaxCountChar(countArray);
    int maxCount = countArray[c - 'a'];

    if (maxCount > (n + 1) / 2) {
        return "";
    }

    string res(n, ' ');
    int idx = 0;

    while (maxCount > 0) {
        res[idx] = c;
        idx += 2;
        maxCount--;
    }

    countArray[c - 'a'] = 0;

    for (int i = 0; i < 26; i++) {
        while (countArray[i] > 0) {
            if (idx >= n) {
                idx = 1;
            }
            res[idx] = 'a' + i;
            idx += 2;
            countArray[i]--;
        }
    }

    return res;
}

    string reorganizeString(string s) {
        return rearrangeString(s);
    }
};