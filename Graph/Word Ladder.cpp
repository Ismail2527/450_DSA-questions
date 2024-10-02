class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        q.push(beginWord);

        int Wordsize=beginWord.size();
        unordered_set<string>word;
        for(int i=0; i<wordList.size(); i++){
            word.insert(wordList[i]);
        }
        if(word.find(endWord) == word.end()) return 0;
        int len = 0; 
        while(!q.empty()){
            len++;
            int qsize = q.size();
            for(int i=0; i<qsize; i++){
                string s = q.front();
                q.pop();
                for(int i=0; i<Wordsize; i++){
                    char ch = s[i];
                    for(char ch1='a'; ch1<='z'; ch1++){
                        s[i] = ch1;
                        if(s == endWord) return len+1;
                        if(word.find(s) == word.end()) continue;

                        word.erase(s);
                        q.push(s);
                    }
                    s[i] = ch;
                }
                
            }
        }
        return 0;
    }
};