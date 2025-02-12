class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int L = beginWord.size(); 
        unordered_map<string,vector<string>> allComboDict;
        for (string word : wordList) {
            for (int i = 0; i < L; i++) {
                string newWord = word.substr(0, i) + '*' + word.substr(i+1, L);
                allComboDict[newWord].push_back(word);
            }
        }
        queue<pair<string,int>> Q;
        Q.push(make_pair(beginWord,1));
        unordered_map<string,bool> visited;
        visited[beginWord] = true;
        while(!Q.empty()) {
            pair<string,int> node = Q.front();
            Q.pop();
            string word = node.first;
            int level = node.second;
            for (int i = 0; i < L; i++) {
                string newWord = word.substr(0,i) + '*' + word.substr(i+1, L);
                for (string adjWord : allComboDict[newWord]) {
                    if (adjWord == endWord) {
                        return level + 1;
                    }
                    if (!visited[adjWord]) {
                        visited[adjWord] = true;
                        Q.push(make_pair(adjWord, level+1));
                    }
                }
            }
        }
        return 0;
    }
};