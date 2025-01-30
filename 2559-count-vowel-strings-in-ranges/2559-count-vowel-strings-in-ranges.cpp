class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = words.size();
        vector<int> counter(n+1,0);
        string vowels = "aeiou";
        for (int i = 0; i < n; i++) {
            string word = words[i];
            if ((word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') 
                && (word[word.size()-1] =='a' || word[word.size()-1] == 'e' || word[word.size()-1] == 'i' || word[word.size()-1] == 'o' || word[word.size()-1] == 'u')) {
                counter[i+1] = counter[i] + 1;
            } else {
                counter[i+1] = counter[i];
            } 
        }
        for (int i = 0; i < queries.size(); i++) {
            ans.push_back(counter[queries[i][1]+1] - counter[queries[i][0]]);
        }
        return ans; 
    }
};